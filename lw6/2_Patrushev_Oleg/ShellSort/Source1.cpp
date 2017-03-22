#include "stdafx.h"
#include "ParallelMergeSorter.h"
#include "LinearMergeSorter.h"

// using namespace std;
// std::vector<int> a = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };  /* target array */
// int arrayLen;
// 
// void merge(int low, int mid, int high)
// {
// 	int left = low;
// 	int right = mid + 1;
// 
// 	std::vector<int> b(high - low + 1);
// 	int i, cur = 0;
// 
// 	while (left <= mid && right <= high) {
// 		if (a[left] <= a[right])
// 			b[cur++] = a[left++];
// 		else
// 			b[cur++] = a[right++];
// 	}
// 
// 	while (left <= mid) b[cur++] = a[left++];
// 	while (right <= high) b[cur++] = a[right++];
// 	cur--;
// 	while (cur >= 0) {
// 		a[low + cur] = b[cur];
// 		cur--;
// 	}
// }
// 
// void mergeSort(int p, int r) {
// 
// 
// 	std::vector<std::future<void>> thread_poolLocal;
// 	int q;
// 
// 	if (p >= r) return;
// 	q = (p + r) / 2;
// 
// 	thread_poolLocal.push_back(std::async(launch::async, mergeSort, p, q));
// 	thread_poolLocal.push_back(std::async(launch::async, mergeSort, q + 1, r));
// 
// 	thread_poolLocal[0].wait();
// 	thread_poolLocal[1].wait();
// 
// 	merge(p, q, r);
// }

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

int main()
{
	//arrayLen = a.size();

	////int i;
	//for (i = 0; i < arrayLen; i++) printf("%d ", a[i]);
	//cout << "\n" << endl;
	//mergeSort(0, arrayLen - 1);

	//for (i = 0; i < arrayLen; i++) printf("%d ", a[i]);
	auto startVec = ReadFromFile("input.txt");

	ParallelMergeSorter pms(startVec);
	LinearMergeSorter lms(startVec);
	
	OutputWorkTime([&]() {lms.MergeSort(0, startVec.size() - 1); });
	OutputWorkTime([&]() {pms.MergeSort(0, startVec.size() - 1); });

	auto result = pms.GetVector();

	//if (std::equal(pms.GetVector().begin(), pms.GetVector().end(), lms.GetVector().begin()))
	//{
	//	std::cout << "ere" << std::endl;
	//}

	//for (auto a : result)
	//{
		//std::cout << a  << " ";
	//}
	//std::cout << std::endl;

	return 0;
}