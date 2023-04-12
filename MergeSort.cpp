#include "MergeSort.h"

void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right){

    int n1 = mid - left + 1;                                // n1 의 값을 mid - left + 1 한 값으로 지정 
    int n2 = right - mid;                                   // n2 의 값을 right - mid 한 값으로 지정
    
    std::vector<int> L(n1);                                 // L 이라는 임시 벡터에 left ~ mid 까지의 데이터가 담긴 n1  저장 
    std::vector<int> R(n2);                                 // R 이라는 임시 벡터에 mid + 1 ~ right 의 데이터가 담긴 n2 저장

    for(int i = 0; i < n1; i++){                            // for 문으로 i 는 L 배열의 현재 위치를 
        L[i] = arr[left + i];

    }
    for(int j = 0; j < n2; j++){                            // for 문으로 j 는 R 배열의 현재 위치를 
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;


    while (i < n1 && j < n2)                                // while 문을 통하여 i < n1 && j < n2 의 조건을 만족하는 동안에
    {
        if(L[i] <= R[j]){                                   // 좌측 배열의[i] 값과 우측 배열의[j] 값을 비교하여
            arr[k] = L[i];                                  // 만약 참이라면 배열의 [k] 번째 인덱스를 좌측 배열의 i 번째 인덱스로 교체
            i++;                                            // 좌측 배열의 다음 인덱스로
        }else
        {                                                   // 만약 좌측 배열이 더 크다면 
            arr[k] = R[j];                                  // 기존 배열의 k 번째는 우측 배열의 J번째 인덱스로 교체
            j++;                                            // 우측 배열의 다음 인덱스로
        }
        k++;                                                // k도 마찬가지로 다음 인덱스로
        
    }
                                                            // 남아있는 좌측 배열의 원소를 arr 뒷 부분에 차례대로 복사
    while (i < n1)                                          // i 가 n1 보다 작다면
    {
        arr[k] = L[i];                                      // arr[k] 번째 요소에 좌측 배열 i 번째 요소를 넣고
        i++;                                                // i 와 k 를 1씩 증가시켜 반복
        k++;

    }

    while (j < n2)                                          // 마찬가지로 우측 배열의 원소를 arr 윗 부분에 차례대로 복사
    {                                                       // j 가 n2 보다 작다면
        arr[k] = R[j];                                      // k 에 j 번째 인덱스 삽입
        j++;                                                // i 와 k 를 1씩 증가시켜 반복
        k++;

    }
    
    
    
}

void MergeSort::merge_sort(std::vector<int> &arr, int left, int right){

    if(left < right){                                        // 재귀함수 종료 조건
        int mid = left + (right - left) / 2;                 // mid ( 배열의 중간 ) 을 left ( 0 ) 과 ( 배열의 최대값 + left ( 0 ) ) 을 2로 나눈 값으로 설정
 

        merge_sort(arr, left, mid);                          // 절반으로 나눈 배열중 왼쪽 배열을 재귀함수에 진입
        merge_sort(arr, mid + 1, right);                     // 절반으로 나눈 배열중 오른쪽 배열을 재귀함수에 진입 ( mid 에서 + 1 시 오른쪽 배열의 시작점 ) 

        merge(arr, left, mid, right);                        // merge 함수 실행
    }
}