#pragma once
#include "MergeSorter.h"

class LinearMergeSorter : public MergeSorter
{
public:
	LinearMergeSorter(const std::vector<int>& vec);
	~LinearMergeSorter() = default;

	void MergeSort(int p, int r) override;
};

