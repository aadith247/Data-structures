#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;

int isfull(struct node *temp)
{
    if(temp==NULL)
    {
        return 1;
    }
    return 0;
}

void push(int d)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=d;
    new->next=NULL;
    if(!isfull(new))
    {
         new->next=top;
         top=new;

    } else {
        printf("The stack over flow happened");
    }

}

int isempty()
{
    return top==NULL;
}

int pop()
{
    if(!isempty())
    {
        struct node *ptr=top;
        int d=top->data;
        top=top->next;
        free(ptr);
        ptr=NULL;
        return d;
        
    } else {

        printf("stack is empty");
        return -1;
            }
           
    
}


int main()
{
    push(89);
    push(24);
    push(25);
    push(12);
    push(456);
     push(89);
    push(24);
    push(25);



    while(!isempty())
    {
        printf(" %d ",pop());
    }

}