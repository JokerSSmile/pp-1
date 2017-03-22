#pragma once
#include "MergeSorter.h"

class ParallelMergeSorter : public MergeSorter
{
public:
	ParallelMergeSorter(const std::vector<int>& vec);
	~ParallelMergeSorter() = default;

	void MergeSort(int p, int r) override;
};
