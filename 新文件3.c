#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *left_child;
	struct node *right_child;
}Node;

void inorder(Node *ptr){
	if(ptr){
		inorder(ptr -> left_child);
		printf("%d ",ptr -> data);
		inorder(ptr -> right_child);
	}
}

Node* pushNodeToTree(Node* nowNode, int n){
	if(nowNode == NULL){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = n;
		newNode->left_child = newNode->right_child = NULL;

		return newNode;
	}
	else {
		if(nowNode->data > n){
			nowNode->left_child = pushNodeToTree(nowNode->left_child, n);
		}
		else {
			nowNode->right_child = pushNodeToTree(nowNode->right_child, n);
		}

		return nowNode;
	}
}

int findParentNode(Node* headPtr, int n){
	if(headPtr == NULL){
		return -1;
	}
	
	if(headPtr->data > n){
		if(headPtr->left_child == NULL){
			return -1;
		}
		else if(headPtr->left_child->data == n){
			return headPtr->data;
		}
		else {
			return findParentNode(headPtr->left_child, n);
		}
	}
	else{
		if(headPtr->right_child == NULL){
			return -1;
		}
		else if(headPtr->right_child->data == n){
			return headPtr->data;
		}
		else {
			return findParentNode(headPtr->right_child, n);
		}
	}

}

int main(void){
	int n;
	Node* headPtr = NULL;

	while(1){
		scanf("%d", &n);
		if(n == -1)
			break;
		// TODO: ��`�I���͵M���itree

		headPtr = pushNodeToTree(headPtr, n);
	}
	// TODO: �L�Xinorder
	inorder(headPtr);
	printf("\n");

	// TODO: ��J�@�ӼƦr�����`�I�A�Y���s�b�A�h�]���-1
	scanf("%d", &n);

	int ans = findParentNode(headPtr, n);
	if(ans == -1)
		printf("�L���`�I");
	else
		printf("%d\n", ans);
	
	
	return 0;
}
