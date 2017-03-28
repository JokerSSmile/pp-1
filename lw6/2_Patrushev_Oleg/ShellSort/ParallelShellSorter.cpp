#include "stdafx.h"
#include "ParallelShellSorter.h"


ParallelShellSorter::ParallelShellSorter(const std::vector<int>& vec)
	: ShellSorter(vec)
	, m_startVecSize(vec.size())
{
}

void ParallelShellSorter::ThreadFunction(int h)
{
	for (size_t i = 0; i < h; i++)
	{
		InsertSort(i, h);
	}
}

void ParallelShellSorter::Sort()
{
	for (size_t h = m_vector.size() / 2; h > 0; h = h / 2)
	{
		m_threads.push_back(std::thread(&ParallelShellSorter::ThreadFunction, this, h));
	}
	std::for_each(m_threads.begin(), m_threads.end(), [](std::thread& thread) { thread.join(); thread.~thread(); });
}

std::vector<int> ParallelShellSorter::GetVector()
{
	return m_vector;
}

