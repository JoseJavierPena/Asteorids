#include "utilities.hpp"
#include "Load.h"

//STDLIB
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Asteroids
{
	namespace Utilities
	{
		std::string const folder_name = "models";

		//Loading models of the ship
		std::vector<Entities::Ship*> Utility::LoadM()
		{
			Engine::FileSystem::Utilities util;
			auto modelsList = util.ListFile(folder_name);

			std::vector<Entities::Ship*> ships;

			std::cout << " *Loaded models* " << std::endl;
				for (int i = 2; i < modelsList.size(); i++)
				{
					std::string model = modelsList[i];
					std::ifstream inFile(util.buildPath(folder_name, model));
					std::string current("");
					std::vector<Vector2> points;

					if (inFile.good())
					{
						std::string getFloat;
						while (inFile >> current)
						{
							std::vector<float> pointsRead;
							getFloat = current.substr(0, current.find_last_of(","));
							pointsRead.push_back(std::stof(getFloat));
							getFloat = current.substr(current.find_last_of(",") + 1, current.length());
							pointsRead.push_back(std::stof(getFloat));

							//Adding to points vector
							points.push_back(Vector2(pointsRead[0], pointsRead[1]));
						}
					}

					std::cout << model << " has " << points.size() << " points" << std::endl;

					//Adding points to temp
					Entities::Ship* temp = new Entities::Ship(points);

					//Adding temp to ships vector, who storages the ships in a vector
					ships.push_back(temp);
				}
			std::cout << std::endl;
			return ships;
		}

	}
}