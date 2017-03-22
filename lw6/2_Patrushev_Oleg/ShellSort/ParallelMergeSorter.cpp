#include "stdafx.h"
#include "ParallelMergeSorter.h"

ParallelMergeSorter::ParallelMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
{
}

void ParallelMergeSorter::MergeSort(size_t l, size_t r)
{
	size_t length = r - l;

	if (length <= 0)
	{
		return;
	}

	size_t q = (l + r) / 2;
	if (length >= m_startVectorLength / 10)
	{
		std::vector<std::thread> threads;
		threads.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, l, q));
		threads.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, q + 1, r));

		std::for_each(threads.begin(), threads.end(), [](std::thread& thread) { thread.join(); });
	}
	else
	{
		MergeSort(l, q);
		MergeSort(q + 1, r);
	}

	Merge(l, q, r);
}
