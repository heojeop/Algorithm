#include <iostream>

struct Node
{
	int data;										// data
	Node* left;										// 왼쪽 Node 의 주소 ( 해당 구조체의 data 보다 작은 값 )
	Node* right;									// 오른쪽 Node 의 주소 ( 해당 구조체의 data 보다 큰 값 )
};

Node* CreateNode(int data) {						// 새로운 노드를 생성하는 함수
	Node* newNode = new Node();
	if (!newNode) {
		std::cerr << "Memory error \n";
		return nullptr;								// newNode 가 생성되지 않았다면 오류 메세지를 출력하고 return
	}

	newNode->data = data;							// newNode ( 새로 생성 한 객체 ) 의 data 에 받아 온 data 파라메터를 삽입
	newNode->left = newNode->right = nullptr;		// 새로 생성 한 객체의 left 와 right 는 최신 데이터 이기 때문에 nullptr
	return newNode;									// 새로 생성 한 객체를 반환
}

Node* insert(Node* root, int data) {				// 노드를 추가하는 함수
	if (root == nullptr) {							// 만약 root ( 부모 ) 가 nullptr 이라면 ( 아무것도 없다면 )
		root = CreateNode(data);					// root  를 CreateNode 함수를 통해 새로 생성
	}
	else if (data < root->data)						// 그게 아니라 만약 insert 하고싶은 data 가 root  의 data 보다 작다면 
	{
		root->left = insert(root->left, data);		// root  의 left ( 좌측 ) 포인터에 insert 함수 ( 재귀함수 ) 실행
	}
	else
	{
		root->right = insert(root->right, data);	// 혹은 우측값이 크다면 우측 포인터에 insert 함수 실행
	}
	return root;
}

Node* minValueNode(Node* root) {					// BST 에서 가장 작은 값을 가지고 있는 노드를 검색하는 함수
	Node* Current = root;							// root  를 Current 에 임시로 저장함
	while (Current && Current->left != nullptr)		// Current의 left ( 좌측값 ) 이 nullptr 이 아닌경우에는 ( 값이 있는 경우 )
	{
		Current = Current->left;					// Current 의 좌측값으로 이동
		return Current;
	}
}

Node* deleteNode(Node* root, int data) {			// 노드를 삭제하는 함수 
	if (root == nullptr) return root;				// 만약 root 가 nullptr 이라면 ( 비어있다면 ) return root ( 의미 없으므로 바로 리턴 )

	if (data < root->data) {						// 만약 삭제하고 싶은 data가 root  의 data 보다 작다면 ? 
		root->left = deleteNode(root->left, data);	// root  의 좌측의 노드로 향하여 동일하게 deleteNode 함수를 실행 
	}
	else if (data > root->data)						// 만약 삭제하고 싶은 data 가 root  의 data 보다 크다면 ?
	{
		root->right = deleteNode(root->right, data);// root  의 우측 노드로 향하여 동일하게 deleteNode 함수를 실행 
	}
	else
	{
		if (root->left == nullptr) {				// 만약 삭제 할 노드의 left 가 nullptr 이라면 ?
			Node* temp = root->right;				// 삭제 할 노드의 우측 데이터를 Temp 에 임시 저장
			delete root;							// 그리고 현재 노드를 삭제
			return temp;							// 삭제 된 노드의 우측 값을 return
		}
		else if (root->right == nullptr) {			// 만약 삭제 할 노드의 right 가 nullptr 이라면 ?
			Node* temp = root->left;				// 삭제 할 노드의 좌측 데이터를 Temp 에 임시 저장 
			delete root;							// 그리고 현재 노드를 삭제
			return temp;							// 삭제 된 노드의 우측 값을 return
		}
		Node* temp = minValueNode(root->right);		// temp ( 삭제 됐던 값 보다 컸던 ) 우측 값을 minValueNode 함수를 실행 ( 우측에서 가장 작은 값을 가진 노드를 찾음 )
		root->data = temp->data;					// 현재 노드의 데이터와 교환함
		root->right = deleteNode(root->right, temp->data);	// 그리고 우측 트리에서는 deleteNode 함수를 사용하여 삭제 
	}
	return root;									// 노드 삭제 후의 root 노드를 반환
}

void inorder(Node* temp) {							// 중위 탐색
	if (temp == nullptr) {							// 만약 nullptr 이면 리턴
		return;
	}

	inorder(temp->left);
	printf("%d ", temp->data);
	inorder(temp->right);
}