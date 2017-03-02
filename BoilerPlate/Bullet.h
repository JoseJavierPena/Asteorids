#pragma once
#ifndef BULLET_H_
#define BULLET_H_

//
#include "Constants.h"
#include "Entity.h"

namespace Asteroids
{
	namespace Entities
	{
		class Bullet : public Entity
		{
		public:
			//Functions
			Bullet(Vector2 pos, Vector2 v, float angle);
			void Render();
			void Update(float fps);
			void wrapAround();
			void rotate(float param1)override { m_angle = param1; };
			void translate(Vector2 pos)override { m_position = pos; };

			//Members
			int m_lifeTime;

		};
	}
}

#endif // !BULLET_H_
