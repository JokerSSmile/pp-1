#pragma once
class MergeSorter
{
public:
	MergeSorter(const std::vector<int>& vec);
	~MergeSorter() = default;

	virtual void MergeSort(size_t p, size_t r) = 0;
	std::vector<int> GetVector();

public:

	void Merge(size_t low, size_t mid, size_t high);

	std::vector<int> m_vector;
	size_t m_startVectorLength;
};

