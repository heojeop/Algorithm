#pragma once
#include <cstdio>
#include "struct.h"

template<typename Type>
class DoubleLinkedList{
    public:
    DoubleLinkedList();
    void Push_front(Type index);
    void Push_Back(Type index);
    void Pop_front(Type index);
    void Pop_back(Type index);
    void insert(STDLikedList<Type>* Node, Type index);
    void erase(STDLikedList<Type>* Node, Type index);


    private:
    STDLikedList<Type>* Head;
    STDLikedList<Type>* Back;

};