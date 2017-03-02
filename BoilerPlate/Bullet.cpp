#include "Bullet.h"

#include "Physic.h"

//SDL
#include "SDL2\SDL_opengl.h"

namespace Asteroids
{
	namespace Entities
	{
		Bullet::Bullet(Vector2 pos, Vector2 v, float angle)
		{
			m_mass = 0.3f;
			m_radius = 7.f;
			m_angle = angle;
			m_angleInRads = (m_angle + Asteroids::Entities::angle) * (Engine::Math::PI / 180);
			m_position = pos;
			m_lifeTime = 0;
		}

		void Bullet::Render()
		{
			m_lifeTime++;

			glLoadIdentity();

			wrapAround();

			glTranslatef(m_position.X, m_position.Y, 0.f);

			glLoadIdentity();
			glBegin(GL_TRIANGLE_FAN);
			int num_segments = 100;
			
			for (int i = 0; i < num_segments; i++)
			{
				float thet = 2.0f * Engine::Math::PI * float(i) / float(num_segments);
				float x = m_radius * cosf(thet);
				float y = m_radius * sinf(thet);
				Vector2 vertex(x + m_position.X, y + m_position.Y);
				glVertex2f(vertex.X, vertex.Y);
			}
			glEnd();
		}

		void Bullet::Update(float fps)
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
			translate(current);

			return;
		}

		void Bullet::wrapAround()
		{
			if (m_position.X > 650)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				translate(invertedPosition);
			}

			else if (m_position.X < -650)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				translate(invertedPosition);
			}

			if (m_position.Y > 400)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				translate(invertedPosition);
			}

			else if (m_position.Y < -400)
			{
				Vector2 invertedPosition(m_position.X * -1, m_position.Y * -1);
				translate(invertedPosition);
			}
		}
	}
}