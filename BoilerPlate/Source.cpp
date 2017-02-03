#include "Header.hpp"
#include <fstream>
#include <dirent.h>
#include <iostream>

Utilities::Utilities()
{
}

Utilities::~Utilities()
{
}

void list_dir(std::string dir)
{
	DIR* directorio;
	struct dirent* elem;
	std::string elem1;
	std::fstream file;
	std::string rdString;

	if (directorio = opendir(dir.c_str()))
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

void init()
{
	std::string dir;

	//Directory of the folder models
	dir = "C:\Users\jose_\Desktop\GitHub\Asteroids\models";
	list_dir(dir.c_str());
}