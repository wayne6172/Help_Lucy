#include <stdio.h>
#include "test.c"

Node* insert(Node* headPtr, int value){
    
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