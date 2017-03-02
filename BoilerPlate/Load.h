#pragma once
#ifndef LOAD_H_
#define LOAD_H_

//
#include <vector>

#include "ship.h"

namespace Asteroids
{
	namespace Utilities
	{
		class Utility
		{
		public:
			//Functions
			std::vector<Entities::Ship*> LoadM();
		};
	}
}


#endif // !LOAD_H_