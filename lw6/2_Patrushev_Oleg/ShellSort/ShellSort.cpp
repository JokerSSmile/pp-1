#include "stdafx.h"
#include "LinearShellSorter.h"
#include "ParallelShellSorter.h"
#include "../MergeSort/HelpUtils.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid program calling. ShellSort.exe <filename>" << std::endl;
		return 1;
	}

	auto inputVector = ReadFromFile(argv[1]);
	LinearShellSorter lss(inputVector);
	ParallelShellSorter pss(inputVector);

	OutputWorkTime([&]() {lss.Sort(); });
	OutputWorkTime([&]() {pss.Sort(); });

    return 0;
}

