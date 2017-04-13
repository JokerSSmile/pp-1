#pragma once
#include "BaseMergeSorter.h"

class CParallelMergeSorter : public CBaseMergeSorter
{
public:
	CParallelMergeSorter(const std::vector<int>& vec);

protected:
	void MergeSort(size_t p, size_t r) override;

private:
	int m_coresCount;
	std::vector<std::thread> m_threads;
};
