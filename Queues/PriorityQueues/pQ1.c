#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX 5
int arr[MAX];
int prior[MAX];
int front=-1;
int rear=-1;

int full()
{
    if(front==MAX-1 && rear==MAX-1)
    {
        return 1;
    } else {
        return 0;    
    }
}

int empty()
{
    if(rear==-1 && front==-1)
    {
        return 1;

    } else {
        return 0;
    }
}

void enqueue(int d,int p)
{
    if(!full())
    {
        if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        arr[rear]=d;
        prior[rear]=p;
    }
    else 
    {
        rear++; 
        arr[rear]=d;
        prior[rear]=p;
    }
        
    } else {
        printf("The queue is full");
        exit(1);
    }
    
}

int peek()
{
    int max=-1;
    int counter=-1;
    for(int i=front;i<=rear;i++)
    {
        if(prior[i]>max)
        {
             max=prior[i];
             counter=i;

        }
    }

    return counter;               // the peek() function returns the index of the element having highest priority...
}

void dequeue()
{
    
    if(!empty() && front!=rear && rear>front)
    {
        int maxIndex=peek();
    for(int j=maxIndex;j<=rear;j++)
    {
        arr[j]=arr[j+1];
        prior[j]=prior[j+1];
    }
    rear--;
     
    } else
    if(!empty() && front==rear)
    {
        front=-1;
        rear=-1;
    } else if(empty()) {
        printf("The queue is empty...");
        exit(1);
    }
     


}

void display(void)
{
    int i;
    for(i=front;i<=rear;i++)
    {
        printf(" %d",arr[i]);
    }
    printf("\n");

}

int main()
{
    enqueue(21,1);
    enqueue(31,4);
    enqueue(41,2);
    enqueue(87,5);
    enqueue(94,3);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();
    return 0;
}