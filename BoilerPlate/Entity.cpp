#include "Entity.h"

namespace Asteroids
{
	namespace Entities
	{
		bool Entity::isColliding(Entity* rhs)
		{
			if (!rhs)
				return false;

			float x;
			x = m_position.X - rhs->m_position.X;
			float y;
			y = m_position.Y - rhs->m_position.Y;

			float rad;
			rad = m_radius + rhs->m_radius;
			float distanceSquared;
			distanceSquared = (x * x) + (y + y);
			
			return rad * rad >= distanceSquared;
		}
	}
}