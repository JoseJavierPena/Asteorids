#pragma once
#ifndef ASTEROID_H_
#define ASTEROID_H_

//STL
#include <vector>


//Asteroids
#include "Vector2.h"
#include "Entity.h"

namespace Asteroids
{
	namespace Entities
	{
		const int max_points = 12;
		const float min_size = 25.f;
		const float max_size = 45.f;

		class Asteroid : public Entity
		{
		public:
			//Enumerators
			struct AsteroidSize
			{
				enum Size
				{
					BIG = 0,
					MEDIUM = 1,
					SMALL = 2,
				};
			};

			//Constructor
			Asteroid();
			Asteroid(AsteroidSize::Size size, Vector2 position);

			//Functions
			void Update(float time);
			void Render();
			AsteroidSize::Size GetSize() const { return m_size; }
			Vector2 getPosition() const { return m_position; }

		protected:
			//Protected functions
			void WrapAround();
			void Rotate(float param1);
			void Translate(Vector2 position);

		private:
			//Functions
			void randomPoints();
			void RandomPosition(float max, float min);
			void randomAngle(float max, float min);

			//Members
			AsteroidSize::Size m_size;
			int m_sizeFactor;
		};
	}
}

#endif // !ASTEROID_H_