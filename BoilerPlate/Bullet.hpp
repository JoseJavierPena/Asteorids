#pragma once
#ifndef BULLET_HPP_
#define BULLET_HPP_

//
#include "Entity.hpp"

namespace Asteroids
{
	class Bullet : public Entity
	{
	public:
		//Functions
		Bullet();
		void ApplyImpulse(Engine::Vector2 impulse) override;
		void Update(float deltaTime, int widht, int height);
		void Render()override;

	private:
		//Members
		float m_lifespan;
		float m_currentLifeSpan;
	};
}

#endif // !BULLET_HPP_