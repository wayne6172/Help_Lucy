#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
	int data;
	struct node *next;
	struct node *left_child;
	struct node *right_child;
};

typedef struct node *node_point;
void trace_data(node_point *ptr);
void insert(node_point *ptr, node_point *worknode, int item);

void insert(node_point *ptr,node_point *worknode,int item)
{
	
	node_point newone = (struct node *)malloc(sizeof(struct node));
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
void trace_data(node_point *ptr){
	node_point tracenode = *ptr;
	
	if(tracenode == NULL){
		printf("no any node");
		return;
	}
	
	while(tracenode != NULL){
		printf("%d  ",tracenode -> data);
		tracenode = tracenode -> next;
	}
}

int main(void){
	int i, j,temp[7], t, deter;
	node_point head = NULL;
	node_point worknode = NULL;
	srand(time(NULL));
	
	for(i=0;i<7;i++){
		t = (rand()%50)+1;

		deter = 0;
		for(j = 0; j < i; j++){
			if(t == temp[j]){
				deter = 1;
				break;
			}
		}

		if(deter == 0)
			temp[i] = t;
		else {
			i--;
		}
	}
	
	printf("開獎球如下 <最後一球為特別號>: \n");
	for(i=0;i<7;i++){
		insert(&head,&worknode,temp[i]);
		worknode=head;
		while(worknode -> next != NULL)
		{
			worknode = worknode -> next;
		}
	} 
	
	trace_data(&head);
	return 0;
}
