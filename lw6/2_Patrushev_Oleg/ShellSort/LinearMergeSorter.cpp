#include "stdafx.h"
#include "LinearMergeSorter.h"

LinearMergeSorter::LinearMergeSorter(const std::vector<int>& vec)
	: MergeSorter(vec)
{
}

void LinearMergeSorter::MergeSort(int p, int r)
{
	if (p >= r) return;
	int q = (p + r) / 2;

	MergeSort(p, q);
	MergeSort(q + 1, r);
	Merge(p, q, r);
}
