#include "stdafx.h"
#include "LinearMergeSorter.h"
#include "SortFunctions.h"

CLinearMergeSorter::CLinearMergeSorter(const std::vector<int>& vec)
	: CBaseMergeSorter(vec)
{
}

void CLinearMergeSorter::MergeSort(size_t p, size_t r)
{
	if (p >= r)
	{
		return;
	}

	size_t q = (p + r) / 2;

	MergeSort(p, q);
	MergeSort(q + 1, r);
	utils::Merge(m_vector, p, q, r);
}