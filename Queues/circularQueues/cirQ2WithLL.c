#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

int isEmpty()
 {
    return (front == NULL && rear == NULL);
}

void enqueue(int data)
 {
    struct node *temp = malloc(sizeof(struct node));

    if (temp == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->data=data;
    temp->next=NULL;

    if (isEmpty()) 
    {
        front = rear = temp;
        rear->next = front;

    } else {
        rear->next = temp;
        rear = temp;
        rear->next = front;
    }
}

void dequeue() 
{
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        
        rear->next = front;
    }
    temp->next = NULL;
    free(temp);
}

void printList() {
    struct node *temp = front;
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

int main() {
    enqueue(89);
    enqueue(22);
    enqueue(45);
    enqueue(56);
    enqueue(34);
    printList();
    dequeue();
    dequeue();
    printList();
}
