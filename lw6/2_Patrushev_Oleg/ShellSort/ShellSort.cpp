#include "stdafx.h"

/*
#include <iostream>

void merge(int a[], int low, int mid, int high)
{
	int left = low;
	int right = mid + 1;

	int b[1];//int b[high - low + 1];
	int i, cur = 0;

	while (left <= mid && right <= high) {
		if (a[left] <= a[right])
			b[cur++] = a[left++];
		else
			b[cur++] = a[right++];
	}

	while (left <= mid) b[cur++] = a[left++];
	while (right <= high) b[cur++] = a[right++];
	cur--;
	while (cur >= 0) {
		a[low + cur] = b[cur];
		cur--;
	}
}

void mergeSort(int a[], int p, int r) {


	std::vector<std::future<void>> thread_pool;
	int q;

	if (p >= r) return;
	q = (p + r) / 2;

	thread_pool.push_back(std::async(std::launch::async, mergeSort, a, p, q));
	thread_pool.push_back(std::async(std::launch::async, mergeSort, a, q + 1, r));

	merge(a, p, q, r);
}


void ThreadFunc(std::vector<int>& num, int& flag, int& temp, int& d)
{
	
}

void ShellParallel(std::vector<int>& num)
{
	std::vector<std::thread> threads;

	
	//threads.push_back(std::thread(ThreadFunc, std::ref(num), gap));

	for (auto &thread : threads) {
		thread.join();
	}
}

std::vector<int> ReadFromFile(const std::string & fileName)
{
	std::vector<int> result;
	std::ifstream file(fileName);
	int elem;
	while (!file.eof())
	{
		file >> elem;
		result.push_back(elem);
	}

	return result;
}

void OutputWorkTime(std::function<void()> callback)
{
	std::chrono::time_point<std::chrono::system_clock> startTime, endTime;

	startTime = std::chrono::system_clock::now();
	callback();
	endTime = std::chrono::system_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << std::endl;
}


int main(int argc, char* argv[])
{
	std::vector<int> vecp = ReadFromFile("input.txt");
	std::vector<int> vecl = ReadFromFile("input.txt");

	std::vector<int> resultl;
	std::vector<int> resultp;
	int* a = &vecp[0];

	OutputWorkTime([&]() {mergeSort(a, 0, vecp.size()); });
	//OutputWorkTime([&]() {resultp = mergeSortParallel(vecp);});
	
	if (std::equal(resultl.begin(), resultl.end(), resultp.begin()))
	{
		std::cout << "ere" << std::endl;
	}

	for (size_t i = 0; i < vecl.size(); i++)
	{
		//std::cout << resultl[i] << "  " << resultp[i] << std::endl;
	}

	return 0;
}
*/