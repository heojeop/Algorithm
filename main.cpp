#include "Header.h"

int main(void) {


	LinkedList Linked;
	Dynamic Dynamic;

	Dynamic.PushBack(5);
	Dynamic.PushBack(4);
	Dynamic.PushBack(2);
	Dynamic.PushBack(41);
	Dynamic.PushBack(32);
	
	Linked.EndInsert(1);
	Linked.FrontInsert(2);
	Linked.FrontInsert(2);

	Dynamic.PrintArray();
	Dynamic.SearchArray(6);
	Dynamic.SearchArray(5);

	Linked.SearchList(0);
	Linked.PrintList();
	return 0;
}
