#pragma once

#ifndef HEADER_H_INCLUDED

#define HEADER_H_INCLUDED

//C++
#include "App.hpp"
#include <iostream>
#include <fstream>
#include "Utilities.hpp"
#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <dirent.h>
#include <vector>

class Utilities
{
public:
	void list_dir(std::string dir);
	void init();

private:
	DIR* directorio;
	struct dirent* elem;
	std::string elem1;
	std::fstream file;
	std::string rdString;

};


#endif // !HEADER_H_INCLUDED