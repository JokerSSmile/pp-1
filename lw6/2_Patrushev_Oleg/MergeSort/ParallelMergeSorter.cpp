#include "stdafx.h"
#include "ParallelMergeSorter.h"

ParallelMergeSorter::ParallelMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
	, m_coresCount(std::thread::hardware_concurrency())
{
}

void ParallelMergeSorter::MergeSort(size_t l, size_t r)
{
	size_t length = r - l;

	if (length <= 0)
	{
		return;
	}

	size_t m = (l + r) / 2;
	
	if (r - l + 1 == m_startVectorLength / (m_coresCount))
	{
		std::cout << "starting thread " << l << " " << r << std::endl;
		std::vector<std::thread> threads;
		threads.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, l, m));
		threads.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, m + 1, r));
			
		std::for_each(threads.begin(), threads.end(), [](std::thread& thread) { thread.join(); thread.~thread(); });
	}
	else
	{
		MergeSort(l, m);
		MergeSort(m + 1, r);
	}

	Merge(l, m, r);
}
