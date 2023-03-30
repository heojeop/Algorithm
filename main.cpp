#include "Header.h"
int main(void) {
	int target = 1;
	BinarySearch bs;
	std::vector<int> VectorArr = { 1, 2, 3, 4, 5 };
	std::list<int> ListArr = { 1, 2, 3, 4, 5 };
	
	Dynamic dynamic;
	dynamic.PushBack(1);
	dynamic.PushBack(2);
	dynamic.PushBack(3);
	dynamic.PushBack(4);
	dynamic.PushBack(5);

	LinkedList linked;
	linked.EndInsert(1);
	linked.EndInsert(2);
	linked.EndInsert(3);
	linked.EndInsert(4);
	linked.EndInsert(5);



	printf("std::vector 결과 = target = %d , index = %d\n", target, bs.Search(VectorArr, target));
	printf("std::list 결과 = target = %d , index = %d\n", target, *bs.Search(ListArr, target));
	printf("DynamicArray 결과 = target = %d , index = %d\n", target, bs.Search(dynamic, target));
	printf("LinkedList 결과 = target = %d , index = %d\n", target, bs.Search(linked, target));
	
	
	
	return 0;
}
