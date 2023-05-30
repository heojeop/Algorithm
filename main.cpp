#include <iostream>
#include <vector>

class BubbleSort {
public: 
	void BubbleSorting(std::vector<int> arr) {			
		for (int i = 0; i < arr.size(); i++) {				//배열의 크기만큼 
			for (int j = 0; j < arr.size() - 1 - i; j++) {	// 배열의 마지막 요소는 제외하고
				if (arr[j] > arr[j + 1]) {					// 만약 J 가 J 의 다음번째 인덱스보다 크다면
					int temp = arr[j];						// 현재 J 를 임시 Temp 에 저장 
					arr[j] = arr[j + 1];					// 현재 J 의 위치와 교환
					arr[j + 1] = temp;						// 교환 완료
				}
			}
		}

		printf("버블 정렬 후 배열 = ");
		for (int i = 0; i < arr.size(); i++) {
			printf("%d ", arr[i]);
		}
			
			printf("\n");
	}
	
};

class SelectionSort {
public :

	void SelectionSorting(std::vector<int> arr) {

		for (int i = 0; i < arr.size() - 1; i++) {		// 배열에서 최소값 구하기
			int minIndex = i;							// 일단 현재 i 값을 저장
			for (int j = i + 1; j < arr.size(); j++) {	// i 값에 + 1 을 더한 ( 다음 인덱스 ) 부터 시작
				if (arr[j] < arr[minIndex]) {			// 만약 J 가 ( i 의 다음 인덱스 ) 보다 작다면  
					minIndex = j;						// 최소값 산출
				}
			}
			// 최소값을 현재 위치와 교환
			int temp = arr[minIndex];					// 임시 temp 변수에 가장 작은 원소의 값을 저장함
			arr[minIndex] = arr[i];						
			arr[i] = temp;								// 자리 교체
		}

		printf("선택 정렬 후 배열 = ");
		for (int i = 0; i < arr.size(); i++) {			// 정렬 된 원소들 출력
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

};

class InsertionSort {
public:

	void InsertionSorting(std::vector<int> arr) {
		for (int i = 1; i < arr.size(); i++) {
			int key = arr[i];   // 현재 비교할 값
			int j = i - 1;

			// key보다 큰 값을 찾아 key를 삽입할 위치를 찾음
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];  // 더 큰 값들을 오른쪽으로 이동
				j--;
			}
			arr[j + 1] = key;  // key를 삽입할 위치에 삽입
		}

		printf("삽입 정렬 후 배열 = ");
		for (int i = 0; i < arr.size(); i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}



};


void printArr(std::vector<int> arr) {
	for (int i = 0; i < arr.size(); i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}



int main() {
	BubbleSort bs;
	SelectionSort Ss;
	InsertionSort Is;

	std::vector<int> BubbleSortArr = { 4 , 1, 8, 9, 2, 5, 7, 2 , 41 ,123 ,45 ,125 ,51};

	printf("버블 정렬 전 배열 = ");
	printArr(BubbleSortArr);
	bs.BubbleSorting(BubbleSortArr);

	std::vector<int> SelectionSortArr = { 4 , 2, 5,9, 8, 7, 3 , 515,1};
	printf("선택 정렬 전 배열 = ");
	printArr(SelectionSortArr);
	Ss.SelectionSorting(SelectionSortArr);


	std::vector<int> InsertionSortArr = { 6512,33,4,12,512,61,123 };


	printf("삽입 정렬 전 배열 = ");
	printArr(InsertionSortArr);
	Is.InsertionSorting(InsertionSortArr);





	

	return 0;
}

