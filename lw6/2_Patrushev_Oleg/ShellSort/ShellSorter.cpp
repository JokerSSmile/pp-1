#include "stdafx.h"
#include "ShellSorter.h"


ShellSorter::ShellSorter(const std::vector<int>& vec)
	: m_vector(vec)
{
}

void ShellSorter::InsertSort(int i, int half) {
	int temp = 0;
	int j = 0;

	for (size_t f = half + i; f < m_vector.size(); f += half)
	{
		j = f;
		while (j > i && m_vector[j - half] > m_vector[j])
		{
			temp = m_vector[j];
			m_vector[j] = m_vector[j - half];
			m_vector[j - half] = temp;
			j -= half;
		}
	}
}


