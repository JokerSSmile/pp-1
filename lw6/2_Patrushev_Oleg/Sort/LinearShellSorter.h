#pragma once
#include "BaseShellSorter.h"

class CLinearShellSorter : public CBaseShellSorter
{
public:
	CLinearShellSorter(const std::vector<int>& vec);

private:
	void ShellSort() override;
};
