#include <stdio.h>
#include <stdlib.h>
 
// {1,6,8,9,2} 刪除9 再插入4

int temp[5] = {1,6,8,9,2};

typedef struct node
{
	int data;
	struct node *next;
	
}*node_point;

void insert(node_point *ptr,node_point *worknode,int item)
{
	node_point newone = malloc(sizeof(struct node));
	if(!(newone)){
		printf("記憶體滿了");
		return; 
	}
	if(*ptr){
		newone -> data = item;
		newone -> next = (*worknode) -> next;
		(*worknode) -> next = newone;
	}
	else{
		newone -> data = item;
		newone -> next = NULL;
		*ptr = newone;
	}
}
void del(node_point *ptr,node_point *worknode,node_point *beforenode){
	if(*ptr){
		if(*beforenode){
			(*beforenode) -> next = (*worknode) -> next;
			free(*worknode);
			(*worknode) = (*beforenode) -> next;
		}
		else{
			*ptr = (*worknode) -> next;
			free(*worknode);
			worknode = ptr;
		}
	}
	else{
		printf(" link is empty");
		return;
	}	
}

void trace_data(node_point *ptr){
	node_point tracenode = *ptr;
	
	if(tracenode == NULL){
		printf("no any node");
		return;
	}
	while(tracenode != NULL){
		printf("%d\t",tracenode -> data);
		tracenode = tracenode -> next;
	}
}
int main(void) {
	
	node_point head = NULL;
	node_point worknode = NULL;
	node_point beforenode = NULL;
	int i;
	
	for(i=0;i<5;i++){
		insert(&head,&worknode,temp[i]);
		worknode = head;
		while(worknode -> next != NULL){
			worknode = worknode -> next;
		}
	}
	//刪除9 
	worknode = head;
	while(worknode -> data != 9){
		worknode = worknode -> next;
	}
	beforenode  = head;
	while(beforenode -> next != worknode){
		beforenode = beforenode -> next;
	}
	del(&head,&worknode,&beforenode);
	
	//增加4
	worknode = head;
	while(worknode -> data != 6){
		worknode = worknode -> next;
	}
	insert(&head,&worknode,4);
	
	trace_data(&head);
	return 0;
}
