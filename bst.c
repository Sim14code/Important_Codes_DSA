#include <stdio.h>
#include <stdlib.h>

struct BST{
    int data;
    int BST* right;
    int BST* left;
}

struct BST* create(int data,struct BST* root){
    if(root==NULL){
    struct BST* node=malloc(struct BST*)sizeof(struct BST);
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    return node;
    }
    if(data<root->data){
        root->left=create(data,left);
    }
    else if(data > root->data){
        root->right=create(data,right);
    }
    return root;
}

int Min(struct BST* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}

int Max(struct BST* root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root->data;
}


int height(struct BST* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}


int countLeafNodes(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countOneTwoChildren(struct Node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->left != NULL || root->right != NULL) {
        count = 1;
    }
    return count + countOneTwoChildren(root->left) + countOneTwoChildren(root->right);
}

struct Node* findMin(struct Node* node) {
    while (node->left != NULL) node = node->left;
    return node;
}

struct Node* delete(struct Node* root, int data) {
    if (root == NULL) return root;
    
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}
