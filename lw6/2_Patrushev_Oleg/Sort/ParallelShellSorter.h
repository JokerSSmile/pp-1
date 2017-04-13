#pragma once
#include "BaseShellSorter.h"

class CParallelShellSorter : public CBaseShellSorter
{
public:
	CParallelShellSorter(const std::vector<int>& vec);

protected:
	void ShellSort() override;

private:
	void ThreadFunction(int h);

	int m_coresCount;
	std::vector<std::thread> m_threads;
};
