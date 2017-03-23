#pragma once
#include "MergeSorter.h"

class LinearMergeSorter : public MergeSorter
{
public:
	LinearMergeSorter(const std::vector<int>& vec);
	~LinearMergeSorter() = default;

	void MergeSort(size_t p, size_t r) override;
};

