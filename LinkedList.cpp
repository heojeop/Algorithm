#include "LinkedList.h"

LinkedList::LinkedList() {
	head = NULL; // ������ HEAD NULL �ʱ�ȭ
}

void LinkedList::FrontInsert(int Data) {			//��� ���濡 �ֽ� ������ ����
	STLinkedList* NewDataNode = new STLinkedList(); //���ο� ��� ��ü ����
	NewDataNode->Data = Data;
	NewDataNode->Next = head;
	head = NewDataNode;
}

void LinkedList::EndInsert(int Data){				//������ ���� ����
	STLinkedList* NewDataNode = new STLinkedList(); //���ο� ��� ����
	NewDataNode->Data = Data;						//���� �� ��ü�� �����͸� Data ���ڷ� ����
	NewDataNode->Next = NULL;						//���Ӱ� ���� �� ��ü�� ������ �����Ƿ� NULL �� ����

	if (head == NULL) {								//���� head �� NULL �̸� ( ����Ʈ�� ��� ������ )
		head = NewDataNode;							//Head �����͸� ���� ������ ��ü�� ����
		return;
	}

	STLinkedList* Current = head;					//���� HEAD �� ��ġ�� ������

	while (Current->Next != NULL)					//���� HEAD �� ��ġ�� ���� ���� ��尡 NULL �� �ƴ϶��
	{
		Current = Current->Next;					//HEAD�� ��ġ�� ���� ���� ���� ( NULL �� �� �� ���� )
															
	}
	Current->Next = NewDataNode;					//NULL �� �ƴٸ� ���� �����͸� ����
	
}


void LinkedList::PrintList() {
	STLinkedList* Current = head;					//���� HEAD�� ������

	while (Current != NULL)							//������ ����� HEAD�� NULL�� �ƴ϶��
	{
		printf("%d ", Current->Data);				//Current �� DATA�� �����
		Current = Current->Next;					//�׸��� ���� �����ͷ� �̵��� 
													//NULL �� �� �� ���� �ݺ�
	}
	printf("\n");
}




