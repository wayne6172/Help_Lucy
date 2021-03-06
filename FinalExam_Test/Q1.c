#include <stdio.h>
#include "test.c"


// Ex. 5 -> 3 -> 1 -> 0
// Your answer, 0 -> 1 -> 3 -> 5
void printReverseList(Node* root){
    if(root == NULL)
        return;

    printReverseList(root->next);
    printf("%d -> ", root->value);
}

int main(int argc, char const *argv[])
{
    Node *headPtr = getTestLinkList(10);
    printList(headPtr);
    printReverseList(headPtr);


    return 0;
}
