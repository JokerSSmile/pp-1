#include "stdafx.h"
#include "BaseShellSorter.h"

CBaseShellSorter::CBaseShellSorter(const std::vector<int>& vec)
	: CBaseSorter(vec)
{
}

void CBaseShellSorter::SortIteration()
{
	ShellSort();
}
