#include "Utilities.hpp"

//List
void Utilities::list_dir(std::string dir)
{
	if(directorio = opendir(dir.c_str()))
	{
		while (elem = readdir(directorio))
		{
			elem1 = elem->d_name;

			if (elem1 != "." && elem1 != "..")
			{
				std::cout << elem1 << std::endl;
				file.open(dir + "/" + elem1.c_str());

				if (file.good())
				{
					while (!file.eof())
					{
						std::getline(file, rdString);
						std::cout << rdString << std::endl;
					}
					std::cout << "" << std::endl;
				}
				file.close();
			}
		}
	}
	closedir(directorio);
}

//Initialization
void Utilities::init()
{
	std::string dir;

	dir = "C:/Users/jose_/Desktop/GitHub/Asteroids/models";
	list_dir(dir.c_str());
}