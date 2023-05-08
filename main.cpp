#include <iostream>
#include <vector>
#include <algorithm>


class PriorityQueue{
	public:
	PriorityQueue(){}

	void push(int value){
		heap.push_back(value);
		siftUp(heap.size() - 1);
	}

	int pop(){

		if(heap.empty()){
			throw std::runtime_error("Empty heap");
		}
		int minValue = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		siftDown(0);

		return minValue;
	}

	bool empty() const{
		return heap.empty();
	}
	private:
	std::vector<int> heap;


	int getParent(int index){
		return (index - 1) / 2;
	}

	int getLeftChild(int index){
		return 2 * index + 1;
	}

	int getRightChild(int index){
		return 2 * index + 2;
	}

	void siftUp(int index){
		while (index > 0 && heap[index] < heap[getParent(index)])
		{
			std::swap(heap[index], heap[getParent(index)]);
			index = getParent(index);
		}
		
	}

	void siftDown(int index){
		int minIndex = index;
		int leftChild = getLeftChild(index);
		int rightChild = getRightChild(index);

		if(leftChild < heap.size() && heap[leftChild] < heap[minIndex]){
			minIndex = leftChild;
		}
		if(rightChild < heap.size() && heap[rightChild] < heap[minIndex]){
			minIndex = rightChild;
		}
		if(index != minIndex){
			std::swap(heap[index], heap[minIndex]);
			siftDown(minIndex);
		}
	}
};

int main(void) {

	PriorityQueue pq;

	pq.push(5);
	pq.push(2);
	pq.push(6);
	pq.push(7);
	pq.push(1);

	while (!pq.empty())
	{
		std::cout << pq.pop() << " ";
	}
	
	return 0;
}


