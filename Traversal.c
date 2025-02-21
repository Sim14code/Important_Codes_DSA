#include <stdio.h>

void inorder{
    if (root==NULL){return -1;}
    inorder(root->left);
    printf("%d",root->data);
    inorder(root_>right);
}
