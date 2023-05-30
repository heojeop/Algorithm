#include <iostream>
#include <vector>

class BubbleSort {
public: 
	void BubbleSorting(std::vector<int> arr) {			
		for (int i = 0; i < arr.size(); i++) {				//�迭�� ũ�⸸ŭ 
			for (int j = 0; j < arr.size() - 1 - i; j++) {	// �迭�� ������ ��Ҵ� �����ϰ�
				if (arr[j] > arr[j + 1]) {					// ���� J �� J �� ������° �ε������� ũ�ٸ�
					int temp = arr[j];						// ���� J �� �ӽ� Temp �� ���� 
					arr[j] = arr[j + 1];					// ���� J �� ��ġ�� ��ȯ
					arr[j + 1] = temp;						// ��ȯ �Ϸ�
				}
			}
		}

		printf("���� ���� �� �迭 = ");
		for (int i = 0; i < arr.size(); i++) {
			printf("%d ", arr[i]);
		}
			
			printf("\n");
	}
	
};

class SelectionSort {
public :

	void SelectionSorting(std::vector<int> arr) {

		for (int i = 0; i < arr.size() - 1; i++) {		// �迭���� �ּҰ� ���ϱ�
			int minIndex = i;							// �ϴ� ���� i ���� ����
			for (int j = i + 1; j < arr.size(); j++) {	// i ���� + 1 �� ���� ( ���� �ε��� ) ���� ����
				if (arr[j] < arr[minIndex]) {			// ���� J �� ( i �� ���� �ε��� ) ���� �۴ٸ�  
					minIndex = j;						// �ּҰ� ����
				}
			}
			// �ּҰ��� ���� ��ġ�� ��ȯ
			int temp = arr[minIndex];					// �ӽ� temp ������ ���� ���� ������ ���� ������
			arr[minIndex] = arr[i];						
			arr[i] = temp;								// �ڸ� ��ü
		}

		printf("���� ���� �� �迭 = ");
		for (int i = 0; i < arr.size(); i++) {			// ���� �� ���ҵ� ���
			printf("%d ",arr[i]);
		}
		printf("\n");
	}

};

class InsertionSort {
public:

	void InsertionSorting(std::vector<int> arr) {
		for (int i = 1; i < arr.size(); i++) {
			int key = arr[i];   // ���� ���� ��
			int j = i - 1;

			// key���� ū ���� ã�� key�� ������ ��ġ�� ã��
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];  // �� ū ������ ���������� �̵�
				j--;
			}
			arr[j + 1] = key;  // key�� ������ ��ġ�� ����
		}

		printf("���� ���� �� �迭 = ");
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

	printf("���� ���� �� �迭 = ");
	printArr(BubbleSortArr);
	bs.BubbleSorting(BubbleSortArr);

	std::vector<int> SelectionSortArr = { 4 , 2, 5,9, 8, 7, 3 , 515,1};
	printf("���� ���� �� �迭 = ");
	printArr(SelectionSortArr);
	Ss.SelectionSorting(SelectionSortArr);


	std::vector<int> InsertionSortArr = { 6512,33,4,12,512,61,123 };


	printf("���� ���� �� �迭 = ");
	printArr(InsertionSortArr);
	Is.InsertionSorting(InsertionSortArr);





	

	return 0;
}

