#pragma once
class MergeSorter
{
public:
	MergeSorter(const std::vector<int>& vec);
	~MergeSorter() = default;

	virtual void MergeSort(int p, int r) = 0;
	std::vector<int> GetVector();

public:

	void Merge(int low, int mid, int high);

	std::vector<int> m_vector;
};

