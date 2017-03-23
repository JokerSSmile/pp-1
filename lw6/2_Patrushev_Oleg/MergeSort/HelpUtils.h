#pragma once
#include "stdafx.h"

std::vector<int> ReadFromFile(const std::string & fileName)
{
	std::vector<int> result;
	std::ifstream file(fileName);
	int elem;
	while (!file.eof())
	{
		file >> elem;
		result.push_back(elem);
	}

	return result;
}

void OutputWorkTime(std::function<void()> callback)
{
	std::chrono::time_point<std::chrono::system_clock> startTime, endTime;

	startTime = std::chrono::system_clock::now();
	callback();
	endTime = std::chrono::system_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << std::endl;
}

