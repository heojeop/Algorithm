#include "DoubleLinkedList.h"

template<typename Type>
DoubleLinkedList<Type>::DoubleLinkedList(){
    Head = NULL;
    Back = NULL;

}
template<typename Type>
void DoubleLinkedList<Type>::Push_front(Type index){

    STDLikedList* NewDataNode = new STDLikedList();
    
    NewDataNode->Data = index;
    NewDataNode->Next = Head;
    NewDataNode->Back = NULL;
    Head = NewDataNode;
    
}

template<typename Type>
void DoubleLinkedList<Type>::Push_Back(Type index){
    
    STDLikedList* NewDataNode = new STDLikedList();

    NewDataNode->Data = index;
    NewDataNode->Next = NULL;
    
    if(Head == NULL){
        Head = NewDataNode;

        return;
    }
    
    STDLikedList* CurrentNode = Head;

    while (Head->Next!= NULL)
    {
        CurrentNode = CurrentNode->Next;
    }
    
    
    

}

template<typename Type>
void DoubleLinkedList<Type>::Pop_front(Type index){

}

template<typename Type>
void DoubleLinkedList<Type>::Pop_back(Type index){
    
}

template<typename Type>
void DoubleLinkedList<Type>::insert(STDLikedList<Type>* Node, Type index){

}

template<typename Type>
void DoubleLinkedList<Type>::erase(STDLikedList<Type>* Node, Type index){

}