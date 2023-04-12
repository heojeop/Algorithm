#include <cstdio>
#include <vector>

class MergeSort{
    public:

    void merge(std::vector<int> &arr, int left, int mid, int right);
    void merge_sort(std::vector<int> &arr, int left, int right);
};