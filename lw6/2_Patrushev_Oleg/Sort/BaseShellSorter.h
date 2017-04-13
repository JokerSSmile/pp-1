#pragma once
#include "BaseSorter.h"

class CBaseShellSorter : public CBaseSorter
{
protected:
	CBaseShellSorter(const std::vector<int>& vec);
	void SortIteration() override;

	virtual void ShellSort() = 0;
};