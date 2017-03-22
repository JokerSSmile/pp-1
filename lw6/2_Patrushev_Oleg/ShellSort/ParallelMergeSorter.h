#pragma once
#include "MergeSorter.h"

class ParallelMergeSorter : public MergeSorter
{
public:
	ParallelMergeSorter(const std::vector<int>& vec);
	~ParallelMergeSorter() = default;

	void MergeSort(size_t p, size_t r) override;
};
