#include <iostream>
#include <vector>


void maxHeaify(std::vector<int> &arr, int n, int i){
	int largest = i;		
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if(left < n && arr[left] > arr[largest]){
		largest = left;
	}
	if(right < n && arr[right] > arr[largest]){
		largest = right;
	}

	if(largest != i){
		std::swap(arr[i], arr[largest]);
		maxHeaify(arr, n, largest);
	}
}

void heapsort(std::vector<int> &arr){
	int n = arr.size();

	for(int i = n / 2 - 1; i >= 0; i--){
		maxHeaify(arr, n, i);
	}
	for(int i = n - 1; i >= 0; i--){
		std::swap(arr[0], arr[i]);
		maxHeaify(arr, i, 0);
	}
}

int main(void) {
	
	std::vector<int> arr = {12, 11, 13, 5, 6, 7};

	heapsort(arr);

	std::cout << "Sorted array is: \n";
	for(int i = 0; i < arr.size(); i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

}


