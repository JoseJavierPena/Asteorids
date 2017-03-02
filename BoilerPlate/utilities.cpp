#include "utilities.hpp"

std::vector<std::string> Engine::FileSystem::Utilities::ListFile(std::string file)
{
	std::string path(getPath(file));
	std::wstring w_path(path.begin(), path.end());
	WIN32_FIND_DATA fileFinder;
	std::vector<std::string> vs;
	HANDLE hFind;
	hFind = FindFirstFile(w_path.c_str(), &fileFinder);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::wstring fname(fileFinder.cFileName);
			vs.push_back(std::string(fname.begin(), fname.end()));
		} while (FindNextFile(hFind, &fileFinder));
	}
	FindClose(hFind);

	return vs;
}

void Engine::FileSystem::Utilities::printUtility(std::vector<std::string> list)
{
	for (int i = 2; i < list.size(); i++)
	{
		std::cout << "File name: " << list.at(i) << std::endl;
		std::cout << std::endl;
		std::cout << "FILE CONTENT :" << std::endl;
		printFileContent(list.at(i));
		std::cout << std::endl;
	}
}

std::string Engine::FileSystem::Utilities::buildPath(std::string pre, std::string pos)
{
	std::string path;
	path = pre + "\\" + pos;
	return path;
}

std::string Engine::FileSystem::Utilities::getPath(std::string file)
{
	wchar_t buff[MAX_PATH];
	GetModuleFileName(NULL, buff, MAX_PATH);
	std::wstring w_dir(buff);
	std::string s_dir(w_dir.begin(), w_dir.end());
	s_dir = s_dir.substr(0, s_dir.find_last_of("\\/"));
	s_dir += "\\" + file;
	std::wstring current(s_dir.begin(), s_dir.end());
	current += L"/*.*";
	return std::string(current.begin(), current.end());
}

void Engine::FileSystem::Utilities::printFileContent(std::string fileName)
{
	std::ifstream inFile(fileName, std::ifstream::in);
	std::string temp("");
	std::string firstnumget;
	std::string secondnumget;
	float n1 = 0.0;
	float n2 = 0.0;

	if (inFile.good())
	{
		while (!inFile.eof())
		{
			inFile >> temp;
			firstnumget = temp.substr(0, temp.find_last_of(","));
			secondnumget = temp.substr(temp.find_last_of(",") + 1, temp.length());
			n1 = std::stof(firstnumget);
			n2 = std::stof(secondnumget);
			std::cout << n1 << "," << n2 << std::endl;
		}
		return;
	}
}
