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
     struct node *root=createNode(10);
    root->left=createNode(110);
    root->right=createNode(200);
    inorder(root);


}