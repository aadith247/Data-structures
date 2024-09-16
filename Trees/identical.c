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



int identical(struct node *root1,struct node *root2)
{
    if(root1==NULL)
    {
        return 0;
        exit(1);
    }
    if(root2==NULL)
    {
        return 0;
        exit(1);
    }
    if(root1==NULL && root2==NULL)
    {
        return 1;
    }
   identical(root->left);
    identical(root->right);

}

int main()
{

    struct node *root1=createNode(1);
    root1->left=createNode(2);
    root1->right=createNode(3);
    root1->right->left=createNode(4);
    root1->right->right=createNode(5);
    root1->right->right->left=createNode(6);

     struct node *root2=createNode(1);
    root2->left=createNode(2);
    root2->right=createNode(3);
    root2->right->left=createNode(4);
    root2->right->right=createNode(5);
    root2->right->right->left=createNode(6);

    if(identical(root1,root2))
    {

        printf("yes");
    }else {
        printf("no");
    }
}