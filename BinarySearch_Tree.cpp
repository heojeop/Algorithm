#include <iostream>

struct Node
{
	int data;										// data
	Node* left;										// ���� Node �� �ּ� ( �ش� ����ü�� data ���� ���� �� )
	Node* right;									// ������ Node �� �ּ� ( �ش� ����ü�� data ���� ū �� )
};

Node* CreateNode(int data) {						// ���ο� ��带 �����ϴ� �Լ�
	Node* newNode = new Node();
	if (!newNode) {
		std::cerr << "Memory error \n";
		return nullptr;								// newNode �� �������� �ʾҴٸ� ���� �޼����� ����ϰ� return
	}

	newNode->data = data;							// newNode ( ���� ���� �� ��ü ) �� data �� �޾� �� data �Ķ���͸� ����
	newNode->left = newNode->right = nullptr;		// ���� ���� �� ��ü�� left �� right �� �ֽ� ������ �̱� ������ nullptr
	return newNode;									// ���� ���� �� ��ü�� ��ȯ
}

Node* insert(Node* root, int data) {				// ��带 �߰��ϴ� �Լ�
	if (root == nullptr) {							// ���� root ( �θ� ) �� nullptr �̶�� ( �ƹ��͵� ���ٸ� )
		root = CreateNode(data);					// root  �� CreateNode �Լ��� ���� ���� ����
	}
	else if (data < root->data)						// �װ� �ƴ϶� ���� insert �ϰ���� data �� root  �� data ���� �۴ٸ� 
	{
		root->left = insert(root->left, data);		// root  �� left ( ���� ) �����Ϳ� insert �Լ� ( ����Լ� ) ����
	}
	else
	{
		root->right = insert(root->right, data);	// Ȥ�� �������� ũ�ٸ� ���� �����Ϳ� insert �Լ� ����
	}
	return root;
}

Node* minValueNode(Node* root) {					// BST ���� ���� ���� ���� ������ �ִ� ��带 �˻��ϴ� �Լ�
	Node* Current = root;							// root  �� Current �� �ӽ÷� ������
	while (Current && Current->left != nullptr)		// Current�� left ( ������ ) �� nullptr �� �ƴѰ�쿡�� ( ���� �ִ� ��� )
	{
		Current = Current->left;					// Current �� ���������� �̵�
		return Current;
	}
}

Node* deleteNode(Node* root, int data) {			// ��带 �����ϴ� �Լ� 
	if (root == nullptr) return root;				// ���� root �� nullptr �̶�� ( ����ִٸ� ) return root ( �ǹ� �����Ƿ� �ٷ� ���� )

	if (data < root->data) {						// ���� �����ϰ� ���� data�� root  �� data ���� �۴ٸ� ? 
		root->left = deleteNode(root->left, data);	// root  �� ������ ���� ���Ͽ� �����ϰ� deleteNode �Լ��� ���� 
	}
	else if (data > root->data)						// ���� �����ϰ� ���� data �� root  �� data ���� ũ�ٸ� ?
	{
		root->right = deleteNode(root->right, data);// root  �� ���� ���� ���Ͽ� �����ϰ� deleteNode �Լ��� ���� 
	}
	else
	{
		if (root->left == nullptr) {				// ���� ���� �� ����� left �� nullptr �̶�� ?
			Node* temp = root->right;				// ���� �� ����� ���� �����͸� Temp �� �ӽ� ����
			delete root;							// �׸��� ���� ��带 ����
			return temp;							// ���� �� ����� ���� ���� return
		}
		else if (root->right == nullptr) {			// ���� ���� �� ����� right �� nullptr �̶�� ?
			Node* temp = root->left;				// ���� �� ����� ���� �����͸� Temp �� �ӽ� ���� 
			delete root;							// �׸��� ���� ��带 ����
			return temp;							// ���� �� ����� ���� ���� return
		}
		Node* temp = minValueNode(root->right);		// temp ( ���� �ƴ� �� ���� �Ǵ� ) ���� ���� minValueNode �Լ��� ���� ( �������� ���� ���� ���� ���� ��带 ã�� )
		root->data = temp->data;					// ���� ����� �����Ϳ� ��ȯ��
		root->right = deleteNode(root->right, temp->data);	// �׸��� ���� Ʈ�������� deleteNode �Լ��� ����Ͽ� ���� 
	}
	return root;									// ��� ���� ���� root ��带 ��ȯ
}

void inorder(Node* temp) {							// ���� Ž��
	if (temp == nullptr) {							// ���� nullptr �̸� ����
		return;
	}

	inorder(temp->left);
	printf("%d ", temp->data);
	inorder(temp->right);
}