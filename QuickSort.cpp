#include "QuickSort.h"

int QuickSort::Partition(std::vector<int> &arr, int low, int high) {
	int pivot = arr[high];												// �Ǻ� ( ������ ) �� �迭�� ���� ������ ���� 
	int i = low - 1;													// -1 �� ���� ���� ���� low �� ����
	
	for (int k = low; k <= high - 1; k++) {								// for �� ����� k �� -1 ���� ����. Pivot �� -1 �������� �ݺ� ����
		if (arr[k] < pivot) {											// �迭�� k ��° ���Ұ� ���� �迭�� �� ( ������ ) ���� �۴ٸ�
			i++;														// i ( low ) �� 1 ���� -> �迭�� ���� ���ҷ� �̵�
			std::swap(arr[i], arr[k]);									// i ��° ( ���� �� ) �迭�� ���ҿ� k ��° ���� ( ���� �ǹ����� ���� ���� ) �� ��ü
		}
	}																	// �ش� for ���� high - 1 ( Pivot ���� ��ĭ �� ) ���� �ݺ�

	std::swap(arr[i + 1], arr[high]);									// i �� ��ĭ ������ �� ���� Pivot �� ���Ҹ� ���� ��ü
	return i + 1;														// ( for ���� ���鼭 Pivot ���� ���� ���� ���ҵ��� ��� �������� ���� �ξ��� ������ + 1 �� ���Ҵ� ������ Pivot �� ������ ���� ������)
}																		// return ���� ���� i��+1 �� ���� = ���� Pivot �� ���� �ڸ��� ���� �̹Ƿ� ���� (Divide)�� ���� �������� ��

void QuickSort::Sort(std::vector<int> &arr, int low, int high) {
	if (low < high) {													// ����Լ��� ���� ���� ( �迭�� ũ�Ⱑ 1 �� �� ������ )
		int pi = Partition(arr, low, high);								// Pi �� ���� ������ Pivot �� �ε����� ����
		Sort(arr, low, pi - 1);											// ������ ������ ���� Pivot ���� ������ ������ ������ �Ǿ� �ִٴ� ������ ���� ������ ���� Pivot �� �������� �ٽ� Partition �Լ� ���� => �ݺ�
	 	Sort(arr, pi + 1, high);										// ������ ���� ���������� ������ ������� �� ����
	}																    // �迭�� ũ�Ⱑ ���� �پ��� 1���� �Ǿ� low ���� high ���� ������ ������ �ȴٸ� ����Լ� Ż��
}


int QuickSort::ReversPartition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int k = low; k <= high - 1; k++) {
		if (arr[k] > pivot) {
			i++;
			std::swap(arr[i], arr[k]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void QuickSort::ReversSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = ReversPartition(arr, low, high);
		ReversSort(arr, low, pi - 1);
		ReversSort(arr, pi + 1, high);
	}
}






