#include "stdafx.h"
#include "SortFunctions.h"

namespace utils
{
void Merge(std::vector<int>& vec, size_t low, size_t mid, size_t high)
{
	size_t left = low;
	size_t right = mid + 1;

	std::vector<int> b(high - low + 1);
	int cur = 0;

	while (left <= mid && right <= high)
	{
		if (vec[left] <= vec[right])
		{
			b[cur++] = vec[left++];
		}
		else
		{
			b[cur++] = vec[right++];
		}
	}

	while (left <= mid)
	{
		b[cur++] = vec[left++];
	}
	while (right <= high)
	{
		b[cur++] = vec[right++];
	}
	cur--;
	while (cur >= 0)
	{
		vec[low + cur] = b[cur];
		cur--;
	}
}

void InsertSort(std::vector<int>& vec, size_t i, size_t half)
{
	size_t temp = 0;
	size_t j = 0;

	for (size_t f = half + i; f < vec.size(); f += half)
	{
		j = f;
		while (j > i && vec[j - half] > vec[j])
		{
			temp = vec[j];
			vec[j] = vec[j - half];
			vec[j - half] = temp;
			j -= half;
		}
	}
}
}