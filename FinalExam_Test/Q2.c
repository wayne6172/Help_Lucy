#include "test.c"

int isExist(TreeNode *root, int value){
	
	if(root == NULL)
		return 0;

	
	if(root->value > value){
		if(root->left == NULL)
			return 0;	
		else if(root->left->value == value)
			return 1;
		else
			return isExist(root->left,value);
	}
	else{
		if(root->right == NULL)
			return 0;	
		else if(root->right->value == value)
			return 1;
		else
			return isExist(root->right,value);
	}
	
	//return 1;
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
