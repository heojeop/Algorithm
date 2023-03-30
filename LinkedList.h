#pragma once
#include "Struct.h"
#include <cstdio>
class LinkedList {
public:
	LinkedList();
	
	void FrontInsert(int Data); // 노드의 맨 앞에 데이터 추가
	void EndInsert(int Data);	// 노드의 맨 뒤에 데이터 추가
	void PrintList();
	int SearchList(int index);
	int GetLength();
	int GetValue(int index);
	
private:
	STLinkedList* Head;
};