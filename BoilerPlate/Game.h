#pragma once
#ifndef GAME_H_
#define GAME_H_

//STD
#include <vector>

//
#include "Vector2.h"
#include "ship.h"
#include "Asteroid.h"
#include "utilities.hpp"
#include "Load.h"

namespace AsteroidsGame
{
	class Game
	{
	public:
		//Functions
		Game(int width, int height);
		~Game();
		void init();
		void Update(float fps);
		void Render();

		//Members
		std::vector<Asteroids::Entities::Ship*> m_ship;
		int m_playerIndex;
		std::vector<Asteroids::Entities::Ship*> m_foes;

	private:
		//Functions
		void checkCollitions();
		void deleteEnemy(Asteroids::Entities::Asteroid*);
		void createDebris(Asteroids::Entities::Asteroid::AsteroidSize::Size, Vector2 pos);
		void createEnemy(int cant, Asteroids::Entities::Asteroid::AsteroidSize::Size, Vector2 pos);

		//Members
		int m_width;
		int m_height;
	};
}

#endif // !GAME_H_