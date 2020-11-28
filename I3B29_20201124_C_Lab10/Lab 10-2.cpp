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

void inorder(struct node* ptr) /* 中序走訪 */
{
  /* prt一開始應該指向樹的根節點 */
  if(ptr)     /* 若ptr非NULL */
  {
    inorder(ptr->left_child);
    printf("%d\n",ptr->data);  
    inorder(ptr->right_child);
  }
}

void GetNode(struct node *  head,struct node * succ, int num)
{
  if(NULL == head)
  {     }

else  if(head->data > num){  //往左走 left_child;

      if(NULL == head->left_child)
head->left_child = succ;
     
     
    GetNode(head->left_child,succ,num); //遞回
   

}
   
else if(head->data < num){ // 往右走 right_child;
     if(NULL == head->right_child)
head->right_child = succ;

GetNode(head->right_child,succ,num);//遞回
    }

 }
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
	int i,temp[7],num;
	node_point head = NULL;
	node_point worknode = NULL;
	srand(time(NULL));
	
	for(i=0;i<7;i++){
		temp[i] =(rand()%50)+1;
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
	/////////////////////////////////
	struct node *ptr = (struct node *)malloc(sizeof(struct node)*7);


	for(i=0;i<7;i++){
	
		(ptr+i)->left_child = NULL;
		(ptr+i)->right_child = NULL;
	}
	

	for(i=0;i<7;i++){
		num = temp[i];
		
		if(!i)
		(ptr)->data =  num;
		
		else{
		(ptr+i)-> data = num ;
		GetNode(ptr,(ptr+i),num);
		}//end else
	}// for
	
	printf("\n");
	printf("排序後 \n");
	inorder(ptr);
	
	free(ptr);
	return 0;
}
