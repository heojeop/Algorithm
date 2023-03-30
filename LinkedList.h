#pragma once
#include "Struct.h"
#include <cstdio>
class LinkedList {
public:
	LinkedList();
	
	void FrontInsert(int Data); // ����� �� �տ� ������ �߰�
	void EndInsert(int Data);	// ����� �� �ڿ� ������ �߰�
	void PrintList();
	int SearchList(int index);
	int GetLength();
	int GetValue(int index);
	
private:
	STLinkedList* Head;
};