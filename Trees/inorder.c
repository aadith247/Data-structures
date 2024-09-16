#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
//1.inorder,pre and post traversal...
//2.create ,insert delete,search,traverse element in bst...
//the tree is 10
//           /  \
//          110 200

struct node* createNode(int d)
{
    struct node *t=malloc(sizeof(struct node ));
    t->data=d;
    t->right=NULL;
    t->left=NULL;
    return t;
}

void inorder(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    } 
    
}
int main()
{
    struct node *root=createNode(10);
    root->left=createNode(110);
    root->right=createNode(200);
    inorder(root);
    
}