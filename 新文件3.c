#include <stdio.h>
#include <stdlib.h>
struct Node
{
	char data;
	struct Node *left_child;
	struct Node *right_child;
};
typedef struct Node node;    /* �w�qNode���c���O�W��node */
typedef node *bt;            /* bt�����Vnode�����Ы��A�O�W*/

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
