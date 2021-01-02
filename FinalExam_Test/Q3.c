#include <stdio.h>
#include "test.c"

Node* insert(Node* headPtr, int value){
	Node *nowPtr = headPtr,*prePtr = NULL;
	Node *newPtr;
	
	while(nowPtr != NULL && nowPtr->value > value){
		prePtr = nowPtr;
		nowPtr = nowPtr->next; 
	} 
	
	newPtr = (Node *)malloc(sizeof(Node));
	newPtr->value = value;
	newPtr->next = NULL;
	
	if(prePtr == NULL)
		headPtr = newPtr;
	else
		prePtr->next = newPtr;
	
    newPtr->next = nowPtr;
    
    return headPtr; 
}

int main(){
    Node *headPtr = getTestLinkList(5);
    printList(headPtr);

    int i, value;
    for(i = 0; i < 5; i++){
        scanf("%d", &value);
        headPtr = insert(headPtr, value);
        printList(headPtr);
    }
    return 0;
}
