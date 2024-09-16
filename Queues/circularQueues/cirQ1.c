#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int front=-1;
int rear=-1;
int MAX=8;
int arr[8];


void dequeue()
{
    
    if(rear==-1 && front==-1)
    {
        printf("The queue underflow sushi cutiee...");
    } else {
        arr[front]=0;
        front++;
        MAX--;
            }
}

void printlist()
{
    if(rear>front)
    {
        for(int i=front;i<=rear;i++)
        {
            printf(" %d",arr[i]);

        }
    } else if(front<=rear)
    {
        for(int i=0;i<MAX;i++)
        {
            printf(" %d",arr[i]);
        }
    }
    printf("\n");
}




void enqueue(int d)
{
    if(rear==MAX-1 && front==0 || front==(rear+1)%MAX)
    {
        printf("The queue is full...sorry bro....so sad for you....😞");
        exit(1);

    } else if(rear==MAX-1 && front!=0)
    {
        rear=0;
        arr[rear]=d;
    } else {
         if(rear==-1 && front==-1)
    {
        front++;
        rear++;
        arr[rear]=d;
    } else {
        rear++;
        arr[rear]=d;
    }
}

    }
   
int main()
{
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    enqueue(17);
    enqueue(18);
    enqueue(19);
    
    printlist();

    dequeue();
    dequeue();
    dequeue();
    printlist();


}