#include "stdafx.h"
#include "ParallelMergeSorter.h"
#include "LinearMergeSorter.h"

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

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid program calling. MergeSort.exe <filename>" << std::endl;
		return 1;
	}

	auto startVec = ReadFromFile(argv[1]);

	ParallelMergeSorter pms(startVec);
	LinearMergeSorter lms(startVec);
	
	OutputWorkTime([&]() {lms.MergeSort(0, startVec.size() - 1); });
	OutputWorkTime([&]() {pms.MergeSort(0, startVec.size() - 1); });

	auto parallelResult = pms.GetVector();
	auto linearResult = lms.GetVector();

	if (std::equal(parallelResult.begin(), parallelResult.end(), linearResult.begin()))
	{
		std::cout << "Results are equal" << std::endl;
	}

	return 0;
}