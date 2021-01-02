#include "test.c"

int isExist(TreeNode *root, int value){
    return 1;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = getTestTree(10);
    int value;


    scanf("%d", &value);
    if(isExist(root, value))
        printf("The value %d is exist in tree", value);
    else
        printf("The value %d is not exist in tree", value);

    return 0;
}
