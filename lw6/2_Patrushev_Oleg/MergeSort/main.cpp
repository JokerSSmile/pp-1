#include "stdafx.h"
#include "ParallelMergeSorter.h"
#include "LinearMergeSorter.h"
#include "HelpUtils.h"

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

	return 0;
}