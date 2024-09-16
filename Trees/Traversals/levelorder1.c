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




struct queue {
    struct node *data;
    struct queue *next;
};

struct queue *front=NULL;
struct queue *rear=NULL;

void enqueue(struct node *nodeElement)
{
    
    struct queue *new=malloc(sizeof(struct queue));
    new->data=nodeElement;
    new->next=NULL;
    if(front==NULL && rear==NULL)
    {
       front=new;
       rear=new;
    } else {
        rear->next=new;
        rear=new;

    }
}

int empty()
{
    if(front==NULL && rear==NULL)
    {
        return 1;
    } else {
        return 0;
    }
}
struct queue* dequeue()
{
    if(!empty())
    {
         struct queue *temp=front;
    front=front->next;
     return temp;

        
    } else {
        return NULL;
    }

   
}



 void levelorder(struct node *root)
 {
    enqueue(root);
    enqueue(NULL);
    while(!empty())
    {
       struct queue *t= dequeue();
       if(t->data==NULL)
       {

        printf("\n");
        if(!empty())
        
        { enqueue(t->data);}
       

       } else {

        printf(" %d ",t->data->data);
        if(t->data->left!=NULL)
        {
              enqueue(t->data->left);

        }
        if(t->data->right!=NULL)
        enqueue(t->data->right);
       }

    }





 }

int main()
{
     struct node *root=createNode(100);
    root->left=createNode(90);
    root->right=createNode(120);

    levelorder(root);




}












