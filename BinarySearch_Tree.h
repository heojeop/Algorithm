#pragma once
#include "Struct.h"

class BinarySearch_Tree
{
public:
	BSTNode* CreateNode(int data);
	BSTNode* insert(int data);
	BSTNode* minValueNode(BSTNode* root);
	BSTNode* deleteNode(BSTNode* root, int data);
	void inorder(BSTNode* temp);
private:

};
