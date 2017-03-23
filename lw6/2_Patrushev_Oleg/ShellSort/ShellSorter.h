#pragma once
class ShellSorter
{
public:
	ShellSorter(const std::vector<int>& vec);
	~ShellSorter() = default;

	virtual void Sort() = 0;
	void InsertSort(int i, int half);
	
protected:
	std::vector<int> m_vector;
};

