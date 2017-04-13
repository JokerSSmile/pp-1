#pragma once
#include "BaseSorter.h"

class CBaseMergeSorter : public CBaseSorter
{
protected:
	CBaseMergeSorter(const std::vector<int>& vec);
	void SortIteration() override;

	virtual void MergeSort(size_t p, size_t r) = 0;
};

