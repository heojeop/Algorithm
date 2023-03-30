#include "LinkedList.h"

LinkedList::LinkedList() {
	Head = NULL; // ������ HEAD NULL �ʱ�ȭ
}

void LinkedList::FrontInsert(int Data) {			//��� ���濡 �ֽ� ������ ����
	STLinkedList* NewDataNode = new STLinkedList();//���ο� ��� ��ü ����
	
	NewDataNode->Data = Data;
	NewDataNode->Next = Head;
	Head = NewDataNode;

}

void LinkedList::EndInsert(int Data){				//������ ���� ����
	STLinkedList* NewDataNode = new STLinkedList(); //���ο� ��� ����
	NewDataNode->Data = Data;						//���� �� ��ü�� �����͸� Data ���ڷ� ����
	NewDataNode->Next = NULL;						//���Ӱ� ���� �� ��ü�� ������ �����Ƿ� NULL �� ����
	if (Head == NULL) {								//���� head �� NULL �̸� ( ����Ʈ�� ��� ������ )
		Head = NewDataNode;							//Head �����͸� ���� ������ ��ü�� ����
		return;
	}

	STLinkedList* Current = Head;					//���� HEAD �� ��ġ�� ������

	while (Current->Next != NULL)					//���� HEAD �� ��ġ�� ���� ���� ��尡 NULL �� �ƴ϶��
	{
		Current = Current->Next;					//HEAD�� ��ġ�� ���� ���� ���� ( NULL �� �� �� ���� )
															
	}
	Current->Next = NewDataNode;					//NULL �� �ƴٸ� ���� �����͸� ����

}


void LinkedList::PrintList() {
	STLinkedList* Current = Head;					//���� HEAD�� ������
	
	printf("LinkedList Print = ");
	while (Current != NULL)							//������ ����� HEAD�� NULL�� �ƴ϶��
	{
		printf("%d ", Current->Data);				//Current �� DATA�� �����
		Current = Current->Next;					//�׸��� ���� �����ͷ� �̵��� 
													//NULL �� �� �� ���� �ݺ�
	}
	
	printf("\n");
}

int LinkedList::SearchList(int index) {
	STLinkedList* Current = Head;

	while (Current != NULL){

		if (Current->Data == index) {
			printf("%d �˻� �Ϸ� \n ", index);
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






