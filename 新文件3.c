#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char data;
	struct Node *left_child;
	struct Node *right_child;
};
typedef struct Node node;    /* 定義Node結構的別名為node */
typedef node *bt;            /* bt為指向node的指標型態別名*/

void inorder(bt ptr){
	if(ptr){
		inorder(ptr -> left_child);
		printf("%c",ptr -> data);
		inorder(ptr -> right_child);
	}
}

int main(void){
	
	
	
	
	return 0;
}
