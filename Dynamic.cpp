#include "Header.h"

Dynamic::Dynamic() {
	m_size = 2;								//�迭�� ������ �ʱ�ȭ
	m_used = 0;								//���� �������� �� (�ε��� ��ȣ)
	m_array = new int[m_size];				//�迭 ������ ����

}
Dynamic::~Dynamic() {

	delete[] m_array;						//�迭 ������ FREE
}


void Dynamic::PushBack(int Data) {			//�迭���� �ڿ� ���Ҹ� ����

	if (m_used < m_size) {					//���� ��ü ����� ���� �����ͺ��� ũ�ٸ� ( ������ �ִٸ� )
		m_array[m_used] = Data;				//���� �ε��� m_used �� Data ����
	}

	if (m_size == m_used) {					//���� ������� ���� �������� ���� ���ٸ�
		int* Temp = new int[m_size];		//�ӽ� ��ü Temp �� ���� ������ ũ�� ��ŭ ����
		//printf("�迭�� �þ���ϴ�.\n"); 
		for (int i = 0; i < m_size; i++){	
			Temp[i] = m_array[i];			//m_size ��ŭ i �� �������� m_array �� �ִ� �����͸� �ӽ� ��ü Temp �� �̵�
		}
		delete[] m_array;					//�׸��� ���� ũ�Ⱑ �۾Ҵ� m_array �� ����
		m_size *= 2;						//�迭�� ��ü ������ 2�� ����
		m_array = new int[m_size];			//�ι� ���� �� �������� m_array ��ü ����

		for (int i = 0; i < m_used; i++) {	
			m_array[i] = Temp[i];			//for ���� �̿��Ͽ� m_array�� �������� ������ŭ Temp ����
		}
		delete[] Temp;						//���� �Ϸ� �Ͽ����� �ӽð�ü Temp ����
		m_array[m_used] = Data;				//�о��� m_array �迭�� ����ڰ� �Է��� �ε����� ���� �ε��� ��ȣ�� ����
 	}

	m_used++;								//�����Ͱ� �ϳ� �߰� �� ������ ������ �� �ϳ��� ����

}

void Dynamic::PrintArray() {				// ��ü �迭 ���
	
	for (int i = 0; i < m_used; i++) {
		printf("%d ", m_array[i]);
	}
	printf("\n");
}

int Dynamic::ArrayCount() {

	return m_used;
}

int Dynamic::MSearch(int index) {
	int m = m_array[index];

	return m;
}

int Dynamic::SearchArray(int index) {

	for (int i = 0; i < m_size; i++) {
		if (m_array[i] == index) {
			printf("%d �� %d ��° �ε����� �ֽ��ϴ�.\n", index, i);
			return index;
		}
		else {
			printf("�˻��Ͻ� %d �� ã�� �� �����ϴ�.\n", index);
			return index;
		}
	}
}


