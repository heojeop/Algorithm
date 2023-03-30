#pragma once

class Dynamic {
public:
	Dynamic();
	~Dynamic();

	void PushBack(int Data);
	void PrintArray();
	int ArrayCount();
	int MSearch(int index);
	int SearchArray(int index);

private:
	int* m_array;
	int m_size;
	int m_used;
};