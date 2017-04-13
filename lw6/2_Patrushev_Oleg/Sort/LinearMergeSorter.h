#pragma once
#include "BaseMergeSorter.h"

class CLinearMergeSorter : public CBaseMergeSorter
{
public:
	CLinearMergeSorter(const std::vector<int>& vec);

private:
	void MergeSort(size_t p, size_t r) override;
};