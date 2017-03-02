#pragma once
#ifndef ENTITY_HPP_
#define  ENTITY_HPP_

//
#include "Vector2.hpp"

namespace Asteroids
{
	class Entity
	{
		struct EntityState
		{
			enum State
			{
				Normal = 0;
				Collided = 1;
				Deleted = 2;
			};
		};

		//Functions
		Entity();
		void ApplyImpulse(Engine::Vector2 impulse);
		void Update(float deltaTime, int width, int height);
		void Render();
		void Teleport(float newX, float newY);
		bool DetectCollision(Entity* entity);
		bool CouldCollide() { return m_state == EntityState::State::Normal; }
		bool IsDisappearing() { return m_state == EntityState::State::Deleted; }
		bool IsColliding() { return m_state == EntityState::State::Collided; }
		float GetX() { return m_position.x; }
		float GetY() { return m_position.y; }

	private:
		//Members
		Engine::Vector2 m_position;
		Engine::Vector2 m_velocity;
		float m_mass;
		EntityState::State m_state;
		float m_radius;
	};
}

#endif // !ENTITY_HPP_