#include "QuickSort.h"

int QuickSort::Partition(std::vector<int> &arr, int low, int high) {
	int pivot = arr[high];												// 피봇 ( 기준점 ) 을 배열의 가장 끝으로 정함 
	int i = low - 1;													// -1 을 가장 낮은 지점 low 로 지정
	
	for (int k = low; k <= high - 1; k++) {								// for 문 입장시 k 는 -1 부터 시작. Pivot 의 -1 지점까지 반복 시작
		if (arr[k] < pivot) {											// 배열의 k 번째 원소가 현재 배열의 끝 ( 기준점 ) 보다 작다면
			i++;														// i ( low ) 를 1 증가 -> 배열의 다음 원소로 이동
			std::swap(arr[i], arr[k]);									// i 번째 ( 증가 후 ) 배열의 원소와 k 번째 원소 ( 현재 피벗보다 작은 원소 ) 와 교체
		}
	}																	// 해당 for 문을 high - 1 ( Pivot 에서 한칸 전 ) 까지 반복

	std::swap(arr[i + 1], arr[high]);									// i 의 한칸 오른쪽 과 현재 Pivot 의 원소를 서로 교체
	return i + 1;														// ( for 문을 돌면서 Pivot 보다 값이 작은 원소들을 모두 왼쪽으로 몰아 두었기 때문에 + 1 한 원소는 무조건 Pivot 의 값보다 작은 값들임)
}																		// return 으로 현재 i의+1 을 리턴 = 최초 Pivot 의 값은 자리가 고정 이므로 분할 (Divide)을 위한 기준점이 됨

void QuickSort::Sort(std::vector<int> &arr, int low, int high) {
	if (low < high) {													// 재귀함수의 종료 조건 ( 배열의 크기가 1 개 일 때까지 )
		int pi = Partition(arr, low, high);								// Pi 는 최초 실행한 Pivot 의 인덱스로 지정
		Sort(arr, low, pi - 1);											// 왼쪽의 값들이 기존 Pivot 보다 작은건 맞지만 정렬이 되어 있다는 보장은 없기 때문에 최초 Pivot 을 기준으로 다시 Partition 함수 진입 => 반복
	 	Sort(arr, pi + 1, high);										// 오른쪽 값도 마찬가지로 동일한 방식으로 재 정렬
	}																    // 배열의 크기가 점점 줄어들어 1개가 되어 low 값과 high 값이 동일한 시점이 된다면 재귀함수 탈출
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






