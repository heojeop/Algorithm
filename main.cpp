#include "DoubleLinkedList.cpp"
int main(void) {

	DLinkedList<int> DL;

	DL.Push_Front(10);
	DL.Push_Back(20);
	DL.Push_Back(30);
	DL.Push_Back(40);
	DL.Push_Back(50);
	DL.Push_Back(60);
	DL.Push_Back(70);
	DL.Push_Back(80);
	DL.Push_Back(90);
	DL.Push_Back(100);

	DL.Pop_Back();
	DL.Pop_front();

	DL.Insert(5, 4);
	DL.Erase(2);
	DL.PrintList();
	
	return 0;
}
