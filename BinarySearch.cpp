#include "BinarySearch.h"


template<class Type>
int BinarySearch::Search(std::vector<Type> &arr, int index){

    int Low = 0;
    int High = arr.size() - 1;

    while (Low <= High)
    {
        int mid = Low + ( High - Low ) / 2 ;
        int mid_value = arr[mid];

        if(mid_value == index){
            return mid;
        }else if(mid_value < index){
            Low = mid + 1;
        }else{
            High = mid - 1;
        }
    }
    
    return -1;
}

int BinarySearch::Search(Dynamic &arr, int index){

}


