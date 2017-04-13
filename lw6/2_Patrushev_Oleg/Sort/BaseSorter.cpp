#include "stdafx.h"
#include "BaseSorter.h"

CBaseSorter::CBaseSorter(const std::vector<int>& inVector)
	: m_vector(inVector)
	, m_startVectorSize(inVector.size())
{
}

std::vector<int> CBaseSorter::GetData() const
{
	return m_vector;
}

void CBaseSorter::Sort()
{
	SortIteration();
}