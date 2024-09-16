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
    if(root==NULL)
    {
        return 0;
    }
   int leftHeight= height(root->left);
   int rightHeight=height(root->right);
   int h=leftHeight>rightHeight?leftHeight:rightHeight;
   return h+1;

}


int main()
{
    struct node *root = createNode(50);
    root->left = createNode(45);
    root->left->left = createNode(40);
    root->left->left->left = createNode(30);
    root->left->left->right = createNode(41);
    root->left->right = createNode(46);
    root->right = createNode(55);
    root->right->left = createNode(52);
    root->right->right = createNode(56);
    root->right->left->right = createNode(54);  // Creating root->right->left->right
    int h = height(root);
    printf("%d\n", h);

  
}

