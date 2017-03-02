#pragma once
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

//STDLIB
#include <iostream>
#include <vector>

//Engine
#include "Vector2.h"
#include "ship.h"
//#include ""

namespace Asteroids
{
	namespace Entities
	{
		const float angle = 90.0f;
		const float playerSpeed = 5.0f;

		class Entity 
		{
		public:
			//Functions
			virtual void Update(float time) { return; };
			virtual void Render() { return; };
			virtual void translate(Vector2 pos) { return; }
			virtual void rotate(float param1) { return; }
			virtual void wrapAround() { return; }

			//Colision
			bool isColliding(Entity* rhs);
			Vector2 m_position;

		protected:
			//Members
			std::vector<Vector2> m_points;
			float m_radius;
			bool m_canCollide;
			float m_mass;
			float m_angle;
			float m_angleInRads;
			
		};
	}
}

#endif // !ENTITY_HPP_