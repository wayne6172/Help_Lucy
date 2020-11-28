#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;


// 5 -> 7 -> 10 -> 17
int sumList(Node* headPtr){
    Node* nowPtr = headPtr;
    int sum = 0;

    while(nowPtr != NULL){
        sum += nowPtr->value;
        nowPtr = nowPtr->next;
    }

    return sum;
}

double averageList(Node* headPtr){
    Node* nowPtr = headPtr;
    int sum = 0, len = 0;

    while(nowPtr != NULL){
        sum += nowPtr->value;
        len++;
        nowPtr = nowPtr->next;
    }

    return (double)sum / len;
}

void printList(Node* headPtr){
    Node* nowPtr = headPtr;

    while(nowPtr != NULL){
        printf("%d ", nowPtr->value);
        nowPtr = nowPtr->next;
    }
    printf("\n");
}

Node* insert(Node* headPtr, int n){
    Node *nowPtr = headPtr, *prePtr = NULL;
    Node *newPtr;

    while(nowPtr != NULL && nowPtr->value < n){
        prePtr = nowPtr;
        nowPtr = nowPtr->next;
    }

    newPtr = (Node *)malloc(sizeof(Node));
    newPtr->value = n;
    newPtr->next = NULL;

    if(prePtr == NULL)
        headPtr = newPtr;
    else 
        prePtr->next = newPtr;
    
    newPtr->next = nowPtr;

    return headPtr;
}

Node* delete(Node* headPtr, int target){
    Node *nowPtr = headPtr, *prePtr = NULL;

    while(nowPtr != NULL && nowPtr->value != target){
        prePtr = nowPtr;
        nowPtr = nowPtr->next;
    }

    if(nowPtr != NULL){
        if(prePtr == NULL)
            headPtr = nowPtr->next;
        else
            prePtr->next = nowPtr->next;

        free(nowPtr);
    }

    return headPtr;
}

int main(){
    int effect, n;
    Node* headPtr = NULL;

    while(1){
        scanf("%d", &effect);
        if(effect == -1)
            break;

        if(effect == 1){
            scanf("%d", &n);
            headPtr = insert(headPtr, n);
        }
        else if(effect == 2){
            scanf("%d", &n);
            headPtr = delete(headPtr, n);
        }
        else if(effect == 3){
            printList(headPtr);
            printf("¦ê¦CÁ`©M¡G%d\n", sumList(headPtr));
            printf("¦ê¦C¥­§¡­È¡G%lf\n", averageList(headPtr));
        }
    }

}