#pragma once
#include "ShellSorter.h"
class LinearShellSorter : public ShellSorter
{
public:
	LinearShellSorter(const std::vector<int>& vec);
	~LinearShellSorter() = default;

	void Sort() override;
};
