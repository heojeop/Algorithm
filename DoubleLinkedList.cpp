#include "Struct.h"
#include <cstdio>
template<class Type>
class DLinkedList {
public:
	
	DLNode<Type>* Head;													//Head 포인터
	DLNode<Type>* Tail;													//Tail 포인터


	DLinkedList() {														//생성자 초기화
		Head = NULL;
		Tail = NULL;
	}
	~DLinkedList() {

	}

	void Push_Front(Type Data) {										//최전방 데이터 삽입

		DLNode<Type>* NewDataNode = new DLNode<Type>();					//새로운 데이터 객체 생성
		NewDataNode->Data = Data;										//새로운 데이터 객체에 데이터 삽입
		if (Head == NULL) {												//만약 Head 가 NULL 이라면
			Head = NewDataNode;											//HEAD 를 새로운 데이터 객체로 지정
			Tail = NewDataNode;										
		}
		else
		{		
			NewDataNode->Next = Head;									
			Head->Prev= NewDataNode;									
			Head = NewDataNode;
			
		}

	}

	void Push_Back(Type Data) {										//리스트 최후방 데이터 삽입
		
		DLNode<Type>* NewDataNode = new DLNode<Type>();				//데이터를 삽입 할 새로운 객체 생성
		NewDataNode->Data = Data;									//생성 된 객체에 데이터 삽입
		if (Head == NULL) {											//만약 HEAD가 NULL 이라면 ( 데이터가 아무것도 없다면 )
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
	
	void Pop_front() {												//가장 앞에있는 원소(데이터)를 제거
		
		DLNode<Type>* Temp = Head;									//HEAD 를 저장 해 둘 임시객체 Temp 생성

		Head = Head->Next;											//어차피 맨 앞 데이터는 삭제 예정이므로 Head를 기존 Head 의 다음 노드로 변경
		if (Head != NULL) {
			Head->Prev = NULL;										//HEAD의 전 노드는 없으므로 NULL
		}
		delete Temp;												//삭제 할 기존 노드 삭제

	}

	void Pop_Back() {												//가장 뒤에있는 원소(데이터)를 제거

		DLNode<Type>* Temp = Tail;									//가장 뒤에있는 TAIL객체를 임시 저장할 TEMP 생성
		
		Tail = Tail->Prev;											
		if (Tail != NULL) {
			Tail->Next = NULL;
		}
		delete Temp;
	}

	void Insert(int index,Type Data) {								//특정 index 번째 요소에 Data 삽입
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