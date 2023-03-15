#pragma once
#include "Header.h"

class Dynamic {
public:
	Dynamic();
	Dynamic(int size);
	~Dynamic();

	void Pop();
	void Push();
	void Print();
	int& operator[](int index);
private:

};