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

void insert(int data,struct node *root)
{

    struct node *new=createNode(data);
     struct node *ptr=root;
    int key=data;
    struct node*prev=root;

    while(ptr!=NULL)
    {    
     if(key>ptr->data)
     {
        prev=ptr;
        ptr=ptr->right;
     } else if(key<ptr->data)
     {
        prev=ptr;
        ptr=ptr->left;
     } 
    }
        if(prev->data>key)
        {
            prev->left=new;
            printf("it inserted successfully");
          
        }else if(prev->data<key)
        {
            prev->right=new;
             printf("it inserted successfully");


        } else if(key==ptr->data || key==prev->data) {
            printf("naah bcoz it's not even possible to insert");
            exit(1);
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
     insert(59,root);
     insert(60,root);
     insert(42,root);
     inorder(root);
     if(root->data!=root->right->data)

    
     

}