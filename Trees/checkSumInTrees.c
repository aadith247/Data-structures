#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node {
    int data;
    struct node *left;
    struct node *right;
};
//Checking whether the sum of elements in the left subtree and sum of elements in the right subtree are equal to the data of the parent...
struct node* createNode(int d)
{
    struct node *t=malloc(sizeof(struct node ));
    t->data=d;
    t->right=NULL;
    t->left=NULL;
    return t;
}

int check(struct node *root)
{

   if(root==NULL)
   {
    return 1;

   } else if(root->left!=NULL && root->right!=NULL){

    int left=check(root->left);
    int right=check(root->right);

    if(left+right==root->data)
    {
        return root->data+root->data;
    } else {
        return 0;
    }

   } else if(root->left==NULL && root->right==NULL)
   {
    return root->data;
   }
   
   


}



int main()
{
   struct node *root = createNode(20);
    root->left = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(2);
    root->right = createNode(10);    // Corrected assignment
    root->right->left = createNode(5); // Corrected assignment
    root->right->right = createNode(2); // Corrected assignment
   int g=check(root);
   if(g==root->data)
   {
    printf("The tree satisfies the condition\n");
   } else {
    printf("the tree does not satisfy the condition");
   }
   
}



