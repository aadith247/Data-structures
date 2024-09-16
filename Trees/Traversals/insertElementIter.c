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
void insert(int data,struct node *root)
{
    struct node *prev=root;
     struct node *new=malloc(sizeof(struct node ));
    new->data=data;
    new->right=NULL;
    new->left=NULL;

    while(root!=NULL)
    {
        if(data < root->data)
        {
            prev=root;
            root=root->left;

        } else 
        if(data > root->data)
        {
            prev=root;
            root=root->right;
        } else
        if(root->data==data)
        {
            printf("Invalid");
            
        }
        
    }
    if(data<prev->data)
    {
        prev->left=new;
    } else {
        prev->right=new;
    }

}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return ;
    }
   printf(" %d ",root->data);
     preorder(root->left);
     preorder(root->right);
}

int main()
{
     struct node *root=createNode(100);
    root->left=createNode(90);
    root->right=createNode(120);
    insert(85,root);
    preorder(root);


}