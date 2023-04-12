#include "MergeSort.h"

void MergeSort::merge(std::vector<int> &arr, int left, int mid, int right){

    int n1 = mid - left + 1;                                // n1 �� ���� mid - left + 1 �� ������ ���� 
    int n2 = right - mid;                                   // n2 �� ���� right - mid �� ������ ����
    
    std::vector<int> L(n1);                                 // L �̶�� �ӽ� ���Ϳ� left ~ mid ������ �����Ͱ� ��� n1  ���� 
    std::vector<int> R(n2);                                 // R �̶�� �ӽ� ���Ϳ� mid + 1 ~ right �� �����Ͱ� ��� n2 ����

    for(int i = 0; i < n1; i++){                            // for ������ i �� L �迭�� ���� ��ġ�� 
        L[i] = arr[left + i];

    }
    for(int j = 0; j < n2; j++){                            // for ������ j �� R �迭�� ���� ��ġ�� 
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;


    while (i < n1 && j < n2)                                // while ���� ���Ͽ� i < n1 && j < n2 �� ������ �����ϴ� ���ȿ�
    {
        if(L[i] <= R[j]){                                   // ���� �迭��[i] ���� ���� �迭��[j] ���� ���Ͽ�
            arr[k] = L[i];                                  // ���� ���̶�� �迭�� [k] ��° �ε����� ���� �迭�� i ��° �ε����� ��ü
            i++;                                            // ���� �迭�� ���� �ε�����
        }else
        {                                                   // ���� ���� �迭�� �� ũ�ٸ� 
            arr[k] = R[j];                                  // ���� �迭�� k ��°�� ���� �迭�� J��° �ε����� ��ü
            j++;                                            // ���� �迭�� ���� �ε�����
        }
        k++;                                                // k�� ���������� ���� �ε�����
        
    }
                                                            // �����ִ� ���� �迭�� ���Ҹ� arr �� �κп� ���ʴ�� ����
    while (i < n1)                                          // i �� n1 ���� �۴ٸ�
    {
        arr[k] = L[i];                                      // arr[k] ��° ��ҿ� ���� �迭 i ��° ��Ҹ� �ְ�
        i++;                                                // i �� k �� 1�� �������� �ݺ�
        k++;

    }

    while (j < n2)                                          // ���������� ���� �迭�� ���Ҹ� arr �� �κп� ���ʴ�� ����
    {                                                       // j �� n2 ���� �۴ٸ�
        arr[k] = R[j];                                      // k �� j ��° �ε��� ����
        j++;                                                // i �� k �� 1�� �������� �ݺ�
        k++;

    }
    
    
    
}

void MergeSort::merge_sort(std::vector<int> &arr, int left, int right){

    if(left < right){                                        // ����Լ� ���� ����
        int mid = left + (right - left) / 2;                 // mid ( �迭�� �߰� ) �� left ( 0 ) �� ( �迭�� �ִ밪 + left ( 0 ) ) �� 2�� ���� ������ ����
 

        merge_sort(arr, left, mid);                          // �������� ���� �迭�� ���� �迭�� ����Լ��� ����
        merge_sort(arr, mid + 1, right);                     // �������� ���� �迭�� ������ �迭�� ����Լ��� ���� ( mid ���� + 1 �� ������ �迭�� ������ ) 

        merge(arr, left, mid, right);                        // merge �Լ� ����
    }
}