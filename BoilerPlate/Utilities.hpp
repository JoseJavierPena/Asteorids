#pragma once
#ifndef _UTILITIES_
#define _UTILITIES_

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <fstream>

namespace Engine
{
	namespace FileSystem
	{
		class Utilities
		{
		public:
			//Functions
			std::vector<std::string> ListFile(std::string file);
			void printUtility(std::vector<std::string> list);
			std::string buildPath(std::string param1, std::string param2);

		protected:
			//Functions
			std::string getPath(std::string file);
			void printFileContent(std::string fileName);

			//Members
			std::vector<std::string> list_of_files;
		};
	}
}

#endif // !_UTILITIES_