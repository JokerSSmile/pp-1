#include "stdafx.h"
#include "LinearMergeSorter.h"

LinearMergeSorter::LinearMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
{
}

void LinearMergeSorter::MergeSort(size_t p, size_t r)
{
	if (p >= r) return;
	size_t q = (p + r) / 2;

	MergeSort(p, q);
	MergeSort(q + 1, r);
	Merge(p, q, r);
}
