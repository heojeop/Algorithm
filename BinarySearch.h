#include <cstdio>
#include <vector>
#include "LinkedList.h"
#include "Dynamic.h"

class BinarySearch{
    
    public:
    template<class Type>
    int Search(std::vector<Type> &arr, int index);
    int Search(Dynamic &arr, int index);
    int Search(LinkedList &arr, int index);
};