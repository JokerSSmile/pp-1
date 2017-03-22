#include "stdafx.h"
#include "ParallelMergeSorter.h"

ParallelMergeSorter::ParallelMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
{
}

void ParallelMergeSorter::MergeSort(int l, int r)
{
	std::vector<std::thread> thread_poolLocal;
	int length = r - l;

	if (length <= 0)
	{
		return;
	}
	int q = (l + r) / 2;
	if (length >= m_startVectorLength / 10)
	{
		thread_poolLocal.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, l, q));
		thread_poolLocal.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, q + 1, r));

		thread_poolLocal[0].join();
		thread_poolLocal[1].join();
	}
	else
	{
		MergeSort(l, q);
		MergeSort(q + 1, r);
	}
	


	Merge(l, q, r);
}
