#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
//Watch the strivers video if you did not understand the logic here...
//in,take u forward ,search for lowest common ancestor in binary tree...
struct node* createNode(int d)
{
    struct node *t=malloc(sizeof(struct node ));
    t->data=d;
    t->right=NULL;
    t->left=NULL;
    return t;
}


struct node* lca(struct node *root,int v1,int v2)
{
    if(root==NULL|| root->data==v1||root->data==v2)
    {
        return root;
    }
    
    struct node *lef=lca(root->left,v1,v2);
    struct node *rig=lca(root->right,v1,v2);
    if(lef==NULL)
    {
        return rig;
    } else if(rig==NULL)
    {
        return lef;
    } else{
        return root;
    }
}

int main()
{
    struct node *root=createNode(5);
    root->left=createNode(7);
    root->right=createNode(8);
    root->left->left=createNode(1);
    root->left->right=createNode(2);
    root->left->right->left=createNode(3);
    root->left->right->right=createNode(4);
    root->right->left=createNode(9);
    root->right->right=createNode(6);
   printf("%d",lca(root,7,4)->data) ;
   printf("\n");
   printf("%d",lca(root,1,2)->data);
   printf("\n");

    printf("%d",lca(root,1,6)->data);
    printf("\n");
    printf("%d",lca(root,9,6)->data);
    printf("\n");
    printf("%d",lca(root,2,8)->data);
    



}