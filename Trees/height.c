


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

int height(struct node *root)
{

   /* if(root==NULL)
    {
        return 0;

    } else
    if(root->left==NULL && root->right==NULL)
    {
        return 0;*/

        
 if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        return 0;
    } 


    else {
        int left=height(root->left);
        int right=height(root->right);

        if(left>right)
        {
            return left+1;
        } else {
            return right+1;
        }




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
     int h=height(root);
     printf("The height of this tree is %d\n",h);
}