#include "stdafx.h"
#include "MergeSorter.h"


MergeSorter::MergeSorter(const std::vector<int>& vec)
	: m_vector(vec)
{

}

std::vector<int> MergeSorter::GetVector()
{
	return m_vector;
}


void MergeSorter::Merge(int low, int mid, int high)
{
	int left = low;
	int right = mid + 1;

	std::vector<int> b(high - low + 1);
	int i, cur = 0;

	while (left <= mid && right <= high) {
		if (m_vector[left] <= m_vector[right])
			b[cur++] = m_vector[left++];
		else
			b[cur++] = m_vector[right++];
	}

	while (left <= mid) b[cur++] = m_vector[left++];
	while (right <= high) b[cur++] = m_vector[right++];
	cur--;
	while (cur >= 0) {
		m_vector[low + cur] = b[cur];
		cur--;
	}
}