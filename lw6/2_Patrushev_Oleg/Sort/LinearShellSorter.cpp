#include "stdafx.h"
#include "LinearShellSorter.h"
#include "SortFunctions.h"

CLinearShellSorter::CLinearShellSorter(const std::vector<int>& vec)
	: CBaseShellSorter(vec)
{
}

void CLinearShellSorter::ShellSort()
{
	for (size_t h = m_vector.size() / 2; h > 0; h = h / 2)
	{
		for (size_t i = 0; i < h; i++)
		{
			utils::InsertSort(m_vector, i, h);
		}
	}
}
