#pragma once

struct STLinkedList
{
	int Data;
	STLinkedList* Next;
};

template<class Type> 
struct DLNode
{
	Type Data = 0;
	DLNode<Type>* Prev = 0;
	DLNode<Type>* Next = 0;
};




