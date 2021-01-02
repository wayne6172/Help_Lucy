#include <stdio.h>
#include "test.c"


// Ex. 5 -> 3 -> 1 -> 0
// Your answer, 0 -> 1 -> 3 -> 5
void printReverseList(Node* root){
	Node *nowPtr = root,*prePtr = NULL;
	Node *newPtr;
	
	while(nowPtr != NULL){
		prePtr = nowPtr;
		nowPtr = nowPtr->next; 
	} 
	
	newPtr = (Node *)malloc(sizeof(Node));
	newPtr->value = ;
	newPtr->next = NULL;
	
	if(prePtr == NULL)
		headPtr = newPtr;
	else
		prePtr->next = newPtr;
	
    newPtr->next = nowPtr;
    
    return headPtr;
    
}

int main(int argc, char const *argv[])
{
    Node *headPtr = getTestLinkList(5);
    printList(headPtr);
    printReverseList(headPtr);

    return 0;
}
