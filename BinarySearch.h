#include <cstdio>
#include <vector>
#include <list>;
#include "LinkedList.h"
#include "Dynamic.h"

class BinarySearch{
    
    public:
    template<class Type>                                                //다른 자료형을 받기 위한 Template
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
    std::list<int>::iterator Search(std::list<Type>& arr, int index) {                   //iterator 를 이용한 탐색

        auto low = arr.begin();                                                          //간소화를 위해 auto 사용
        auto high = arr.end();                                                           //low 에는 시작지점 , high 에는 끝 지점을 할당
            
        while (low != high) {                                                            //만약 low 와 high 가 동일하지 않다면 루프 시작
            auto mid = std::next(low, std::distance(low, high) / 2);                     //low 에 low 와 high 의 거리를 알려주는 distance 함수를 이용하여 next 값을 mid 에 할당함
                                                                                         
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