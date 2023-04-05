#pragma once
#include <cstdio>
#include <vector>

class QuickSort {
public:
	int Partition(std::vector<int>& arr, int low, int high);
	void Sort(std::vector<int> &arr, int low, int high);

	int ReversPartition(std::vector<int>& arr, int low, int high);
	void ReversSort(std::vector<int>& arr, int low, int high);

	
};