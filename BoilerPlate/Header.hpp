#pragma once

//C++
#include <iostream>
#include <fstream>
#include <vector>
#include <tchar.h>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <dirent.h>

class Utilities
{
public:
	 Utilities();
	~ Utilities();
	void list_dir(std::string dir);
	void init();
};