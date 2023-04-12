#include "Header.h"
int main(void) {
	
	QuickSort Qs;
	MergeSort Ms;
	std::vector<int> arr1 = { 51, 240, 120, 40, 150, 412, 195 };
	std::vector<int> arr2 = { 51, 240, 120, 40, 150, 412, 195 };
	std::vector<int> arr3 = { 51, 240, 120, 40, 150, 412, 195 };

	Ms.merge_sort(arr1, 0, arr1.size() - 1);
	Qs.Sort(arr2, 0, arr2.size() - 1);
	std::sort(arr3.begin(), arr3.end());

	printf("== MergeSort == \n ");
	for (int i = 0; i < arr1.size(); i++) {
		printf("%d ", arr1[i]);
	}

	
	printf("\n == QuickSort == \n ");

	for (int i = 0; i < arr2.size(); i++) {
		printf("%d ", arr2[i]);
	}

	printf("\n == std::Sort == \n ");

	for (int i = 0; i < arr3.size(); i++) {
		printf("%d ", arr3[i]);
	}
	
	return 0;
}
