#include "stdafx.h"
#include "ParallelMergeSorter.h"

ParallelMergeSorter::ParallelMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
{
}

void ParallelMergeSorter::MergeSort(int p, int r)
{
	std::vector<std::thread> thread_poolLocal;

	if (p >= r) return;
	int q = (p + r) / 2;

	thread_poolLocal.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, p, q));
	thread_poolLocal.push_back(std::thread(&ParallelMergeSorter::MergeSort, this, q + 1, r));

	thread_poolLocal[0].join();
	thread_poolLocal[1].join();


	Merge(p, q, r);
}
