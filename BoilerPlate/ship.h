#pragma once

#ifndef _SHIP_
#define _SHIP_

//STD
#include <vector>

//
#include "Physic.h"
#include "Bullet.h"
#include "Entity.h"
#include "Constants.h"

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			//Functions
			Ship(std::vector<Vector2> model_points);
			void Render();
			void Update(float time);
			void MoveUp();
			void RotateRight();
			void RotateLeft();
			void Shoot();
			void Respawn();
			bool canCollide() const { return m_inmune; };
			void setCollision(bool status) { m_inmune = status; };
			void setSpeed(Vector2 v) { m_velocity = v; };
			Vector2 getPosition() const { return m_position; };
			void deleteBullet(Bullet*);

			//Members
			std::vector<Bullet*> m_gun;

		protected:
			//Functions
			void wrapAround() override;
			void rotate(float param1)override;
			void translate(Vector2 position)override;

		private:
			//Function
			void mass();
			void ResetOrientation();

			//Members
			Vector2 m_velocity;
			bool m_inmune;
			int m_respawnTime;
			int m_usedBullets;
			float m_currentSpeed;
		};
	}
}

#endif // !_SHIP_