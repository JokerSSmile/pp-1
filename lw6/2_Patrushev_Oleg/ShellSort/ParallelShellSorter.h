#pragma once
#include "ShellSorter.h"
class ParallelShellSorter : public ShellSorter
{
public:
	ParallelShellSorter(const std::vector<int>& vec);
	~ParallelShellSorter() = default;

	void ThreadFunction(int h);
	void Sort() override;
	std::vector<int> GetVector();

private:
	std::vector<std::thread> m_threads;
	size_t m_startVecSize;
	
};

