#include "LinkedList.h"

LinkedList::LinkedList() {
	Head = NULL; // 생성시 HEAD NULL 초기화
}

void LinkedList::FrontInsert(int Data) {			//노드 전방에 최신 데이터 삽입
	STLinkedList* NewDataNode = new STLinkedList();//새로운 노드 객체 생성
	
	NewDataNode->Data = Data;
	NewDataNode->Next = Head;
	Head = NewDataNode;

}

void LinkedList::EndInsert(int Data){				//데이터 삽입 정의
	STLinkedList* NewDataNode = new STLinkedList(); //새로운 노드 생성
	NewDataNode->Data = Data;						//생성 된 객체의 데이터를 Data 인자로 삽입
	NewDataNode->Next = NULL;						//새롭게 생성 된 객체의 다음은 없으므로 NULL 로 정의
	if (Head == NULL) {								//만약 head 가 NULL 이면 ( 리스트가 비어 있으면 )
		Head = NewDataNode;							//Head 포인터를 새로 삽입한 객체로 변경
		return;
	}

	STLinkedList* Current = Head;					//현재 HEAD 의 위치를 가져옴

	while (Current->Next != NULL)					//현재 HEAD 의 위치에 만약 다음 노드가 NULL 이 아니라면
	{
		Current = Current->Next;					//HEAD의 위치를 다음 노드로 변경 ( NULL 이 될 때 까지 )
															
	}
	Current->Next = NewDataNode;					//NULL 이 됐다면 다음 데이터를 삽입

}


void LinkedList::PrintList() {
	STLinkedList* Current = Head;					//현재 HEAD를 가져옴
	
	printf("LinkedList Print = ");
	while (Current != NULL)							//가져온 노드의 HEAD가 NULL이 아니라면
	{
		printf("%d ", Current->Data);				//Current 의 DATA를 출력함
		Current = Current->Next;					//그리고 다음 포인터로 이동함 
													//NULL 이 될 때 까지 반복
	}
	
	printf("\n");
}

int LinkedList::SearchList(int index) {
	STLinkedList* Current = Head;

	while (Current != NULL){

		if (Current->Data == index) {
			printf("%d 검색 완료 \n ", index);
			return index;
		}
		Current = Current->Next;
		
	}
}

int LinkedList::GetLength() {
	
	STLinkedList* Current = Head;
	int Count = 0;
	while (Current != NULL)
	{
		Current = Current->Next;
		Count++;
	}

	return Count;
}

int LinkedList::GetValue(int index) {

	STLinkedList* Current = Head;
	int Count = 0;

	while (Count < index)
	{
		Current = Current->Next;
		Count++;
	}

	return Current->Data;
}






