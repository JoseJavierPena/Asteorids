#include "Game.h"
#include <Windows.h>
#include <algorithm>

namespace AsteroidsGame
{
	Game::Game(int WIDTH, int HEIGHT)
		: m_width(WIDTH)
		, m_height(HEIGHT)
		, m_playerIndex(0)
	{}

	Game::~Game()
	{
		for (int i = 0; i < m_ship.size() - 1; i++)
			delete m_ship.at(i);

		for (int i = 0; i < m_foes.size() - 1; i++)
			delete m_foes.at(i);
	}

	void Game::init()
	{
		//Loading Ships or PLayer Models
		Asteroids::Utilities::Utility config;
		m_ship = config.LoadM();

		//Creating the asteroids
		createEnemy(5, Asteroids::Entities::Asteroid::AsteroidSize::Size::BIG, NULL);

		return;
	}

	void Game::Update(float fps)
	{
		//Update player
		m_ship[m_playerIndex]->Update(fps);

		//Update enemies
		for (int i = 0; i < m_foes.size(); i++)
			m_foes.at(i)->Update(fps);

		//Check collitions
		checkCollitions();

		return;
	}

	void Game::Render()
	{
		// Render player
		m_ship[m_playerIndex]->Render();

		// Render enemies
		for (int i = 0; i < m_foes.size(); i++)
			m_foes[i]->Render();

		return;
	}

	void Game::checkCollitions()
	{
		if (!m_ship[m_playerIndex]->canCollide()) return;

		int i = 0;
		bool bulletHit = false;
		for (auto temp : m_foes)
		{
			Asteroids::Entities::Asteroid* pAsteroid = dynamic_cast<Asteroids::Entities::Asteroid*>(temp);
			if (pAsteroid)
			{
				if (m_ship[m_playerIndex]->isColliding(pAsteroid))
				{
					//Getting size for debris
					Asteroids::Entities::Asteroid::AsteroidSize::Size currentSize = pAsteroid->GetSize();

					//Deleting asteroid
					deleteEnemy(temp);

					//Creating debris
					createDebris(currentSize, m_ship[m_playerIndex]->getPosition());

					//Respawn
					m_ship[m_playerIndex]->Respawn();
					break;
				}

				for (int i = 0; i < m_ship[m_playerIndex]->m_gun.size(); i++)
				{
					if (m_ship[m_playerIndex]->m_gun[i]->isColliding(pAsteroid))
					{
						//Getting size for debris
						Asteroids::Entities::Asteroid::AsteroidSize::Size currentSize = pAsteroid->GetSize();
						Vector2 currentPos = pAsteroid->getPosition();

						//Deleting asteroid
						deleteEnemy(temp);

						//Deleting bullet
						m_ship[m_playerIndex]->deleteBullet(m_ship[m_playerIndex]->m_gun[i]);
						//Creating debris
						createDebris(currentSize, currentPos);
						bulletHit = true;
					}
				}
				if (bulletHit == true)
					break;
			}
		}
		return;
	}

	void Game::createEnemy(int cant, Asteroids::Entities::Asteroid::AsteroidSize::Size size, Vector2 pos)
	{
		if (pos == NULL)
		{
			for (int i = 0; i < cant; i++)
			{
				Asteroids::Entities::Asteroid* nEnemy = new Asteroids::Entities::Asteroid();
				m_foes.push_back(nEnemy);
			}
			return;
		}

		else
		{
			for (int i = 0; i < cant; i++)
			{
				Asteroids::Entities::Asteroid* nEnemy = new Asteroids::Entities::Asteroid(size, pos);
				m_foes.push_back(nEnemy);
			}
		}

	}

	void Game::deleteEnemy(Asteroids::Entities::Asteroid* dEnemy)
	{
		m_foes.erase(remove(m_foes.begin(), m_foes.end(), dEnemy), m_foes.end());
		delete dEnemy;
	}

	void Game::createDebris(Asteroids::Entities::Asteroid::AsteroidSize::Size size, Vector2 pos)
	{
		if (size == Asteroids::Entities::Asteroid::AsteroidSize::BIG)
		{
			createEnemy(3, Asteroids::Entities::Asteroid::AsteroidSize::Size::MEDIUM, pos);
		}

		if (size == Asteroids::Entities::Asteroid::AsteroidSize::Size::MEDIUM)
		{
			createEnemy(3, Asteroids::Entities::Asteroid::AsteroidSize::Size::SMALL, pos);
		}
	}
}