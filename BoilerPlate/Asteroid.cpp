#include "Asteroid.h"

//
#include <SDL2\SDL_opengl.h>
#include <time.h>

//
#include "Constants.h"
#include "Vector2.h"
#include "Physic.h"

namespace Asteroids
{
	namespace Entities
	{
		Asteroid::Asteroid()
		{
			m_mass = 0.7f;
			m_size = Asteroid::AsteroidSize::Size::BIG;
			m_sizeFactor = static_cast<int> (m_size);
			randomPoints();
			RandomPosition(350, 600);
			randomAngle(2, 4);
			m_angleInRads = (angle + Asteroids::Entities::angle) * (Engine::Math::PI / 180);

			if (m_size == AsteroidSize::BIG)
			{
				m_radius = 40.f;
			}

			if (m_size == AsteroidSize::MEDIUM)
			{
				m_radius = 20.f;
			}

			if (m_size == AsteroidSize::SMALL)
			{
				m_radius = 10.f;
			}			
		}

		Asteroid::Asteroid(Asteroid::AsteroidSize::Size size, Vector2 position)
			: m_size(size)
		{
			m_points.resize(max_points);
			m_size = size;
			m_position = position;
			randomPoints();
			randomAngle(2, 24);
			m_angleInRads = (m_angle + angle) * (Engine::Math::PI / 180);

			if (size == AsteroidSize::BIG) m_radius = 40.f;
			if (size == AsteroidSize::MEDIUM) m_radius = 20.f;
			if (size == AsteroidSize::SMALL) m_radius = 10.f;

			m_sizeFactor = static_cast<int> (size) + 1;

		}

		void Asteroid::Render()
		{
			glLoadIdentity();
			
			WrapAround();

			glTranslatef(m_position.X, m_position.Y, 0.0f);
			
			glBegin(GL_LINE_LOOP);

			for (auto temp : m_points)
			{
				glVertex2f(temp.X, temp.Y);
			}

			glEnd();

			return;
		}

		void Asteroid::Update(float time)
		{
			Vector2 current;

			if (m_mass > 0)
			{
				float impulse = (Physics::thrust / m_mass);
				float x = impulse * std::cosf(m_angleInRads);
				float y = impulse * std::sinf(m_angleInRads);

				current += Vector2(x, y);
			}

			current += m_position;
			Translate(current);

			return;
		}

		void Asteroid::WrapAround()
		{
			if (m_position.X > 650)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				Translate(invertedPosition);
			}

			else if (m_position.X < -650)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				Translate(invertedPosition);
			}

			if (m_position.Y > 400)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				Translate(invertedPosition);
			}
			else if (m_position.Y < -400)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				Translate(invertedPosition);
			}
		}

		void Asteroid::Rotate(float param1)
		{
			m_angle += param1;
		}

		void Asteroid::Translate(Vector2 pos)
		{
			m_position = pos;
			return;
		}

		void Asteroid::randomPoints()
		{
			int sizeFactor = static_cast<int>(m_size) + 1;
			float min = min_size / sizeFactor;
			float max = max_size / sizeFactor;

			for (int i = 0; i < max_points; ++i)
			{
				const float radians = (i / static_cast<float>(max_points));
				const float randDist = Engine::Math::randomRange<float>(min, max);

				m_points.push_back(Vector2(sinf(radians) * randDist, cosf(radians) * randDist));
			}
		}

		void Asteroid::RandomPosition(float Xmax , float Ymax)
		{
			float x = Engine::Math::randomRange<float>(-Xmax, Xmax);
			float y = Engine::Math::randomRange<float>(-Ymax, Ymax);

			m_position.X = x;
			m_position.Y = y;
		}

		void Asteroid::randomAngle(float min, float max)
		{
			m_angle = Engine::Math::randomRange<float>(min, max);
		}
	}
}