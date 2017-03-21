#include "stdafx.h"

std::mutex mutex;

void ShellLinear(std::vector<int>& vec)
{
	size_t length = vec.size();
	for (size_t step = vec.size() / 2; step > 0; step /= 2)
	{
		for (size_t i = step; i < length; i++)
		{
			size_t j;
			int tempValue;
			tempValue = vec[i];
			for (j = i; j >= step; j -= step)
			{
				if (tempValue < vec[j - step])
				{
					vec[j] = vec[j - step];
				}
				else
				{
					break;
				}
			}
			vec[j] = tempValue;
		}
	}
}

void ThreadFunc(std::vector<int>& vec, size_t step)
{
	size_t length = vec.size();
	for (size_t i = step; i < length; i++)
	{
		size_t j;
		int tempValue;
		tempValue = vec[i];
		mutex.lock();
		for (j = i; j >= step; j -= step)
		{
			if (tempValue < vec[j - step])
			{
				vec[j] = vec[j - step];
			}
			else
			{
				break;
			}
		}
		vec[j] = tempValue;
		mutex.unlock();
	}
}

void ShellParallel(std::vector<int>& vec)
{
	std::vector<std::thread> threads;

	for (size_t step = vec.size() / 2; step > 0; step /= 2)
	{
		threads.push_back(std::thread(ThreadFunc, std::ref(vec), step));
	}
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
	std::vector<int> vecp = ReadFromFile("input1.txt");
	std::vector<int> vecl = ReadFromFile("input1.txt");

	OutputWorkTime([&]() {ShellLinear(vecl);});
	OutputWorkTime([&]() {ShellParallel(vecp);});
	
	//if (std::equal(vecp.begin(), vecp.end(), vecl.begin()))
	//{
	//	std::cout << "ere" << std::endl;
	//}

	for (size_t i = 0; i < vecl.size(); i++)
	{
		std::cout << vecl[i] << "  " << vecp[i] << std::endl;
	}

	return 0;
}