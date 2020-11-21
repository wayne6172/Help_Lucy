#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}Node;

int main(){
    Node *headPtr = NULL, *newNode;
    int n;

    while(1){
        scanf("%d", &n);

        if(n == -1)
            break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->value = n;

        newNode->next = headPtr;
        headPtr = newNode;
    }

    Node *nowNode = headPtr;
    
    for(nowNode = headPtr;nowNode != NULL;nowNode = nowNode->next;){
        printf("%d\n", nowNode->value);
    } 
}
