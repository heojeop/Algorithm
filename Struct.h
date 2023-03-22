#pragma once

struct STLinkedList
{
	int Data;
	STLinkedList* Next;
};


template<typename Type> struct STDLikedList
{
	Type Data;
	STDLikedList* Prev;
	STDLikedList* Next;
};


