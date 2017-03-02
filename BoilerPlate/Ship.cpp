#include "ship.h"
#include "Physic.h"

//SDL
#include <SDL2/SDL_opengl.h>

//STD
#include <cmath>
#include <algorithm>

namespace Asteroids
{
	namespace Entities
	{
		Ship::Ship(std::vector<Vector2> model_points)
			: m_velocity()
			, m_usedBullets(0)
		{
			m_points = model_points;
			m_radius = 40.f;
			m_angle = 0.f;
			m_angleInRads = 0.f;
			mass();
			m_respawnTime = 0;
			m_currentSpeed = 0.f;
		}

		void Ship::Render()
		{
			// Respawn delay
			if (!m_inmune)
			{
				if (m_respawnTime >= 120)
				{
					setCollision(true);
					m_respawnTime = 0;					
				}
				m_respawnTime++;
			}

			// Reset matrix
			glLoadIdentity();

			// Wrap around call
			wrapAround();

			// Translation to ship position
			glTranslatef(m_position.X, m_position.Y, 0.0f);

			// Ship rotation to current angle
			glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

			// Ship drawing
			glBegin(GL_LINE_LOOP);

			for (auto temp : m_points)
			{
				glVertex2f(temp.X, temp.Y);
			}
			glEnd();

			m_angleInRads = (m_angle + Asteroids::Entities::angle) * (Engine::Math::PI / 180);

			for (int i = 0; i < m_gun.size(); i++)
				m_gun[i]->Render();


			return;
		}

		void Ship::MoveUp()
		{
			// Making impulse and rotation
			if (m_mass > 0)
			{
				float impulse = (Physics::thrust / m_mass);
				float x = impulse * std::cosf(m_angleInRads);
				float y = impulse * std::sinf(m_angleInRads);

				m_velocity += Vector2(x, y);
			}
		}

		void Ship::RotateRight()
		{
			rotate(-5.0f);
		}

		void Ship::RotateLeft()
		{
			rotate(5.0f);
		}

		void Ship::Shoot()
		{
			if (m_usedBullets == 5) return;
			else if (m_usedBullets < 5)
			{
				Bullet* nBullet = new Bullet(m_position, m_velocity, m_angle);
				m_gun.push_back(nBullet);
				m_usedBullets++;
			}
		}

		void Ship::translate(Vector2 pos)
		{
			// Change ship position
			m_position = pos;
		};

		void Ship::rotate(float num)
		{
			// Changing angle
			m_angle += num;
			m_angleInRads = (m_angle + Asteroids::Entities::angle) * (Engine::Math::PI / 180);
		};

		void Ship::Update(float deltaTime)
		{
			// Speed limit - not working -
			float speed = std::fabs(m_velocity.Length());
			if (speed > Physics::max_Speed)
			{
				m_velocity = Vector2(
					(m_velocity.X / speed) * Physics::max_Speed,
					(m_velocity.Y / speed) * Physics::max_Speed
				);

				m_currentSpeed = std::fabs(m_velocity.m_length);
			}

			// Applying drag
			m_velocity = Vector2(
				m_velocity.X * Physics::drag,
				m_velocity.Y * Physics::drag);

			// Calculating new position
			Vector2 pos = m_position + m_velocity;

			// Translation to new position
			translate(pos);

			//Update existing bullets
			for (int i = 0; i < m_gun.size(); i++)
			{
				m_gun[i]->Update(deltaTime);
				if (m_gun[i]->m_lifeTime >= 240)
				{
					deleteBullet(m_gun[i]);
					break;
				}
			}
			return;
		}

		void Ship::Respawn()
		{
			setCollision(false);
			m_position = Vector2(0.f);
			ResetOrientation();		
			setSpeed(Vector2(0.f, 0.f));
		};

		void Ship::wrapAround()
		{
			if (m_position.X > 650)
			{
				Vector2 invertedPos(m_position.X * -1, m_position.Y * -1);
				translate(invertedPos);
			}
			else if (m_position.X < -650)
			{
				Vector2 invertedPos(m_position.X * -1, m_position.Y * -1);
				translate(invertedPos);
			}

			if (m_position.Y > 400)
			{
				Vector2 invertedPos(m_position.X * -1, m_position.Y * -1);
				translate(invertedPos);
			}
			else if (m_position.Y < -400)
			{
				Vector2 invertedPos(m_position.X * -1, m_position.Y * -1);
				translate(invertedPos);
			}
		};

		void Ship::deleteBullet(Bullet* dBullet)
		{
			m_gun.erase(remove(m_gun.begin(), m_gun.end(), dBullet), m_gun.end()
			);
			delete dBullet;
			m_usedBullets--;
		}

		void Ship::mass()
		{
			for (auto count : m_points)
			{
				m_mass += 0.2f;
			}

			if (m_mass < 1.0f)
				m_mass = 1.5f;

			return;
		}

		void Ship::ResetOrientation()
		{
			m_angle = 0.f;
			m_angleInRads = 0.f;
		}
	}
}