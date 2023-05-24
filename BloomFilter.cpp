#include <iostream>
#include <functional>
#include <vector>

class BloomFilter{

	std::vector<bool> filter;
	int size;

	public:
	BloomFilter(int i) : size(i){
		filter.resize(i,false);	
	}

	void insert(int key){
		std::hash<int> hash_fn1;
		std::hash<long> hash_fn2;
		filter[hash_fn1(key) % size] = true;
		filter[hash_fn2(key) % size] = true;
	}

	bool search(int key){
		std::hash<int> hash_fn1;
		std::hash<long> hash_fn2;
		return filter[hash_fn1(key) % size] && filter[hash_fn2(key) % size];
	}


};