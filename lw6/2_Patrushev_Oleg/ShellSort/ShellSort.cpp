#include "stdafx.h"
#include "LinearShellSorter.h"
#include "ParallelShellSorter.h"
#include "../MergeSort/HelpUtils.h"

int main()
{
	auto inputVector = ReadFromFile("input.txt");
	LinearShellSorter lss(inputVector);
	ParallelShellSorter pss(inputVector);

	OutputWorkTime([&]() {lss.Sort(); });
	OutputWorkTime([&]() {pss.Sort(); });

    return 0;
}

