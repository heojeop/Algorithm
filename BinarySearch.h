#include <cstdio>
#include <vector>
#include <list>;
#include "LinkedList.h"
#include "Dynamic.h"

class BinarySearch{
    
    public:
    template<class Type>                                                //�ٸ� �ڷ����� �ޱ� ���� Template
    int Search(std::vector<Type>& arr, int index) {                    
        int Low = 0;                                                    
        int High = arr.size() - 1;                                      

        while (Low <= High)
        {
            int mid = Low + (High - Low) / 2;
            int mid_value = arr[mid];

            if (mid_value == index) {
                return mid;
            }
            else if (mid_value < index) {
                Low = mid + 1;
            }
            else {
                High = mid - 1;
            }
        }

        return -1;
    }

    int Search(Dynamic& arr, int index) {
        int low = 0;
        int high = arr.ArrayCount() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int mid_value = arr.MSearch(mid);

            if (mid_value == index) {
                return mid;
            }
            else if (mid_value < index) {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }

        }

        return -1;
    }
    template<class Type>
    std::list<int>::iterator Search(std::list<Type>& arr, int index) {                   //iterator �� �̿��� Ž��

        auto low = arr.begin();                                                          //����ȭ�� ���� auto ���
        auto high = arr.end();                                                           //low ���� �������� , high ���� �� ������ �Ҵ�
            
        while (low != high) {                                                            //���� low �� high �� �������� �ʴٸ� ���� ����
            auto mid = std::next(low, std::distance(low, high) / 2);                     //low �� low �� high �� �Ÿ��� �˷��ִ� distance �Լ��� �̿��Ͽ� next ���� mid �� �Ҵ���
                                                                                         
            if (*mid == index) {
                return mid;
            }
            else if (*mid < index) {
                low = std::next(mid);
            }
            else {
                high = mid;
            }
        }

        return arr.end();
        
    }   

    int Search(LinkedList& arr, int index) {
        
        int low = 0;
        int high = arr.GetLength();

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int mid_value = arr.GetValue(mid);

            if (mid_value == index) {
                return mid;
            }
            else if (mid_value < index) {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
};