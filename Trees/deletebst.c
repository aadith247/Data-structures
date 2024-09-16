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

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    } 
    else {
        return;
    }
    
}


void delete(int data,struct node *root)
{
    struct node *ptr=root;
    struct node *prev=ptr;
    while(ptr!=NULL)
    {
        if()
    }




}
    
    






int main()
{
    struct node *root=createNode(50);
    root->left=createNode(45);
    root->left->left=createNode(40);
    root->left->left->left=createNode(30);
     root->left->left->right=createNode(41);
     root->left->right=createNode(46);

     root->right=createNode(55);
     root->right->left=createNode(53);
     root->right->left->left=createNode(52);
     root->right->left->right=createNode(54);
     root->right->right=createNode(56);
     delete(41,root);
     delete(56,root);
     delete(40,root);
     inorder(root);

    
     

}