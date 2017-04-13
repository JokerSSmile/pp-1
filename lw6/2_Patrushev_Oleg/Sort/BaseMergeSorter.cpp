#include "stdafx.h"
#include "BaseMergeSorter.h"

CBaseMergeSorter::CBaseMergeSorter(const std::vector<int>& vec)
	: CBaseSorter(vec)
{
}

void CBaseMergeSorter::SortIteration()
{
	MergeSort(0, m_startVectorSize - 1);
}