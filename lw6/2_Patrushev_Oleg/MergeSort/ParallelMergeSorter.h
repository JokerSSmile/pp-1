#pragma once
#include "MergeSorter.h"

class ParallelMergeSorter : public MergeSorter
{
public:
	ParallelMergeSorter(const std::vector<int>& vec);
	~ParallelMergeSorter() = default;

	void MergeSort(size_t p, size_t r) override;

private:
	int m_coresCount;
	std::vector<std::thread> m_threads;
	std::mutex m_mutex;
};
