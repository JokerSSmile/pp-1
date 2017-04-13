#include "stdafx.h"
#include "ParallelShellSorter.h"
#include "SortFunctions.h"

CParallelShellSorter::CParallelShellSorter(const std::vector<int>& vec)
	: CBaseShellSorter(vec)
{
}

void CParallelShellSorter::ThreadFunction(int h)
{
	for (size_t i = 0; i < h; i++)
	{
		utils::InsertSort(m_vector, i, h);
	}
}

void CParallelShellSorter::ShellSort()
{
	for (size_t h = m_vector.size() / 2; h > 0; h = h / 2)
	{
		m_threads.push_back(std::thread(&CParallelShellSorter::ThreadFunction, this, h));
	}
	std::for_each(m_threads.begin(), m_threads.end(), [](std::thread& thread) { thread.join(); thread.~thread(); });
}
