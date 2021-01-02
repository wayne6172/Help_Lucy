#include <stdio.h>
#include <stdlib.h>

#ifndef _COMPILE_TEST
#define _COMPILE_TEST

typedef struct node{
    int value;
    struct node *next;
}Node;

typedef struct treeNode{
    int value;
    struct treeNode *left, *right;
}TreeNode;

Node* getTestLinkList(int size){
    srand((unsigned)time(NULL));

    Node *headPtr = NULL, *newPtr;
    int i, preValue = rand() % 20;

    for(i = 0; i < size; i++){
        newPtr = (Node *)malloc(sizeof(Node));
        preValue = newPtr->value = rand() % 10 + preValue;
        newPtr->next = headPtr;
        headPtr = newPtr;
    }

    return headPtr;
}

TreeNode* insertTree(TreeNode* root, int value){
    if(root == NULL){
        TreeNode *newPtr = malloc(sizeof(TreeNode));
        newPtr->left = newPtr->right = NULL;
        newPtr->value = value;

        return newPtr;
    }

    if(root->value > value)
        root->left = insertTree(root->left, value);
    else
        root->right = insertTree(root->right, value);

    return root;
}

void inorder(TreeNode *root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

TreeNode* getTestTree(int size){
    srand((unsigned)time(NULL));
    TreeNode *root = NULL;
    int i;
    for(i = 0; i < size; i++){
        root = insertTree(root, rand() % 50);
    }

    inorder(root);
    printf("\n");
    return root;
}

void printList(Node* headPtr){
    while(headPtr){
        printf("%d -> ", headPtr->value);
        headPtr = headPtr->next;
    }
    printf("NULL\n");
}

#endif
