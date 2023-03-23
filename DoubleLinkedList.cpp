#include "Struct.h"
#include <cstdio>
template<class Type>
class DLinkedList {
public:
	
	DLNode<Type>* Head;													//Head ������
	DLNode<Type>* Tail;													//Tail ������


	DLinkedList() {														//������ �ʱ�ȭ
		Head = NULL;
		Tail = NULL;
	}
	~DLinkedList() {

	}

	void Push_Front(Type Data) {										//������ ������ ����

		DLNode<Type>* NewDataNode = new DLNode<Type>();					//���ο� ������ ��ü ����
		NewDataNode->Data = Data;										//���ο� ������ ��ü�� ������ ����
		if (Head == NULL) {												//���� Head �� NULL �̶��
			Head = NewDataNode;											//HEAD �� ���ο� ������ ��ü�� ����
			Tail = NewDataNode;										
		}
		else
		{		
			NewDataNode->Next = Head;									
			Head->Prev= NewDataNode;									
			Head = NewDataNode;
			
		}

	}

	void Push_Back(Type Data) {										//����Ʈ ���Ĺ� ������ ����
		
		DLNode<Type>* NewDataNode = new DLNode<Type>();				//�����͸� ���� �� ���ο� ��ü ����
		NewDataNode->Data = Data;									//���� �� ��ü�� ������ ����
		if (Head == NULL) {											//���� HEAD�� NULL �̶�� ( �����Ͱ� �ƹ��͵� ���ٸ� )
			Head = NewDataNode;
			Tail = NewDataNode;
		}
		else
		{
			Tail->Next = NewDataNode;
			NewDataNode->Prev = Tail;
			Tail = NewDataNode;
		}

	}
	
	void Pop_front() {												//���� �տ��ִ� ����(������)�� ����
		
		DLNode<Type>* Temp = Head;									//HEAD �� ���� �� �� �ӽð�ü Temp ����

		Head = Head->Next;											//������ �� �� �����ʹ� ���� �����̹Ƿ� Head�� ���� Head �� ���� ���� ����
		if (Head != NULL) {
			Head->Prev = NULL;										//HEAD�� �� ���� �����Ƿ� NULL
		}
		delete Temp;												//���� �� ���� ��� ����

	}

	void Pop_Back() {												//���� �ڿ��ִ� ����(������)�� ����

		DLNode<Type>* Temp = Tail;									//���� �ڿ��ִ� TAIL��ü�� �ӽ� ������ TEMP ����
		
		Tail = Tail->Prev;											
		if (Tail != NULL) {
			Tail->Next = NULL;
		}
		delete Temp;
	}

	void Insert(int index,Type Data) {								//Ư�� index ��° ��ҿ� Data ����
		DLNode<Type>* Current = Head;
		DLNode<Type>* NewDataNode = new DLNode<Type>();
		NewDataNode->Data = Data;

		
		for (int i = 0; i < index - 2; i++) {
			Current = Current->Next;
		}
		NewDataNode->Next = Current->Next;
		NewDataNode->Prev = Current;
		Current->Next = NewDataNode;


	}

	void Erase(int index) {

		DLNode<Type>* Current = Head;
		int count = 0;
		while (Current != nullptr && count < index) {
			Current = Current->Next;
			count++;
		}
		if (Current == nullptr) {
			return;
		}
		if (Current == Head) {
			Head = Current->Next;
		}
		if (Current == Tail) {
			Tail = Current->Prev;
		}
		if (Current->Prev != nullptr) {
			Current->Prev->Next = Current->Next;
		}
		if (Current->Next != nullptr) {
			Current->Next->Prev = Current->Prev;
		}

		delete Current;
	}


	void PrintList() {
		
		DLNode<Type>* Current = Head;
		while (Current != NULL)
		{
			printf("%d\n", Current->Data);
			Current = Current->Next;
		}
	}

};