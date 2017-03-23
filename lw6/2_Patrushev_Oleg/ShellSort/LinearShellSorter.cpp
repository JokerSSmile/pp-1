#include "stdafx.h"
#include "LinearShellSorter.h"


LinearShellSorter::LinearShellSorter(const std::vector<int>& vec)
	: ShellSorter(vec)
{
}

void LinearShellSorter::Sort()
{
	for (size_t h = m_vector.size() / 2; h > 0; h = h / 2)
	{
		for (size_t i = 0; i < h; i++)
		{
			InsertSort(i, h);
		}
	}
}

