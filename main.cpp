#include "Header.h"
int main(void) {
	
	QuickSort QS;
	std::vector<int> arr = { 30, 50, 20, 10, 80, 42, 99 };
	int n = arr.size();

	printf(" Sort = ");
	QS.Sort(arr, 0, n - 1);
	for (const auto& element : arr) {
		printf("%d ", element);
	}
	printf("\n");
	QS.ReversSort(arr, 0, n - 1);

	printf(" ReversSort = ");
	for (const auto& element : arr) {
		printf("%d ", element);
	}

	return 0;
}
