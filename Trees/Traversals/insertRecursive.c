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
struct node* insert(int x,struct node *root)
{
    struct node *new=createNode(x);
    if(root==NULL)
    {
        return new;

    } else if(x<root->data)
    {
        root->left=insert(x,root->left);
    } else {
        root->right=insert(x,root->right);
    }
    return root;
}
void inorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
 
     inorder(root->left);
       printf(" %d ",root->data);
     inorder(root->right);
}

int main()
{
    struct node *root=createNode(100);
    root->left=createNode(90);
    root->right=createNode(120);
    insert(85,root);
    inorder(root);

}
 