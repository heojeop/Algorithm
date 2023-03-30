#include "Header.h"

Dynamic::Dynamic() {
	m_size = 2;								//배열의 사이즈 초기화
	m_used = 0;								//현재 데이터의 양 (인덱스 번호)
	m_array = new int[m_size];				//배열 포인터 정의

}
Dynamic::~Dynamic() {

	delete[] m_array;						//배열 포인터 FREE
}


void Dynamic::PushBack(int Data) {			//배열가장 뒤에 원소를 삽입

	if (m_used < m_size) {					//만약 전체 사이즈가 현재 데이터보다 크다면 ( 공간이 있다면 )
		m_array[m_used] = Data;				//현재 인덱스 m_used 에 Data 삽입
	}

	if (m_size == m_used) {					//만약 사이즈와 현재 데이터의 양이 같다면
		int* Temp = new int[m_size];		//임시 객체 Temp 를 현재 데이터 크기 만큼 생성
		//printf("배열이 늘어났습니다.\n"); 
		for (int i = 0; i < m_size; i++){	
			Temp[i] = m_array[i];			//m_size 만큼 i 를 증가시켜 m_array 에 있는 데이터를 임시 객체 Temp 로 이동
		}
		delete[] m_array;					//그리고 기존 크기가 작았던 m_array 는 삭제
		m_size *= 2;						//배열의 전체 사이즈 2배 증가
		m_array = new int[m_size];			//두배 증가 한 사이즈의 m_array 객체 생성

		for (int i = 0; i < m_used; i++) {	
			m_array[i] = Temp[i];			//for 문을 이용하여 m_array에 데이터의 갯수만큼 Temp 복사
		}
		delete[] Temp;						//복사 완료 하였으면 임시객체 Temp 삭제
		m_array[m_used] = Data;				//넓어진 m_array 배열에 사용자가 입력한 인덱스를 현재 인덱스 번호에 삽입
 	}

	m_used++;								//데이터가 하나 추가 될 때마다 데이터 양 하나씩 증가

}

void Dynamic::PrintArray() {				// 전체 배열 출력
	
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
			printf("%d 는 %d 번째 인덱스에 있습니다.\n", index, i);
			return index;
		}
		else {
			printf("검색하신 %d 을 찾을 수 없습니다.\n", index);
			return index;
		}
	}
}


