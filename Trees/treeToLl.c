#include <stdio.h>
#include <stdlib.h>
struct tree{
    int data;
    struct tree* left;
    struct tree *right;
};
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;

void insertatend(int data)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(head==NULL)
    {
        head=new;
        tail=new;


    }
    else{
        tail->next=new;
        new->prev=tail;
        tail=new;

    }


}

struct tree* createNode(int d)
{
    struct tree *t=malloc(sizeof(struct node));
    t->data=d;
    t->left=NULL;
    t->right=NULL;
    return t;
}

void convert2Ll(struct tree *root)
{
    if(root==NULL)
    {

        return;
    }
 
    convert2Ll(root->left);
    insertatend(root->data);
    convert2Ll(root->right);


}

void print()
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;

    }



}

int main()
{
    struct tree *root=createNode(11);
    root->left=createNode(12);
    root->right=createNode(15);
    root->left->left=createNode(20);
    root->left->right=createNode(30);
    root->right->left=createNode(36);

    convert2Ll(root);
    print();


}