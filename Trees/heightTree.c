#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int d)
{
    struct node *t=malloc(sizeof(struct node ));
    t->data=d;
    t->right=NULL;
    t->left=NULL;
    return t;
}

int height(struct node *root){
    if(root==NULL)
    {
        return 0;
    } else {
         int left=height(root->left);
         int right=height(root->right);
         return left>right?left+1:right+1;
    }
}


int main()
{
    struct node *root=createNode(1);
    root->left=createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    int h=height(root);

    printf("The height of the tree is %d",h);
    
}