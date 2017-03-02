#pragma once
#ifndef ASTEROID_HPP_
#define ASTEROID_HPP_

// STL
#include <vector>

//Asteroids
#include "Vector2.hpp"
#include "Entity.hpp"

namespace Asteroids
{
	class Asteroid : public Entity
	{
	public:

		//Size of the asteroid
		struct AsteroidSize
		{
			enum Size
			{
				BIG = 0;
				MEDIUM = 1;
				SMALL = 2;
			};
		};

		//Functions
		Asteroid(AsteroidSize::Size size);
		void ApplyImpulse(Engine::Vector2 impulse) override;
		void Update(float deltaTime, int width, int height);
		void Render() override;
		AsteroidSize::Size GetSize();

	private:
		//Members
		std::vector<Engine::Vector2> m_points;
		AsteroidSize::Size m_size;
		int m_sizeFactor;
		float m_angle;
		float m_rotation;
	};
}

#endif // !ASTEROID_HPP_