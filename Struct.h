#pragma once


struct STLinkedList
{
	int Data;
	STLinkedList* Next;
};

struct DynamicArray
{
	int* m_array;
	int m_size;
	int m_used;
};