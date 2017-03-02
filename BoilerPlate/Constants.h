#pragma once
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace Engine
{
	namespace Math
	{
		const float PI = 3.141592653f;

		template<typename C>
		C randomRange(C min, C max)
		{
			return min + (max - min) * (rand() / static_cast<C>(RAND_MAX));
		}
	}
}

#endif // !CONSTANTS_H_
