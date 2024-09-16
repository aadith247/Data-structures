#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

struct Queue {
    Node* front;
    Node* rear;
};

typedef struct Queue Queue;

void enqueue(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->front->data;
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

void concatenateQueues(Queue* q1, Queue* q2) {
    if (q1->front == NULL) {
        q1->front = q2->front;
    } else {
        q1->rear->next = q2->front;
    }
    if (q2->rear != NULL) {
        q1->rear = q2->rear;
    }
    q2->front = NULL;
    q2->rear = NULL;
}

void display(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q1 = {NULL, NULL};
    Queue q2 = {NULL, NULL};

    enqueue(&q1, 1);
    enqueue(&q1, 2);
    enqueue(&q1, 3);

    enqueue(&q2, 4);
    enqueue(&q2, 5);
    enqueue(&q2, 6);

    printf("Queue 1: ");
    display(&q1);
    printf("Queue 2: ");
    display(&q2);

    concatenateQueues(&q1, &q2);
    printf("Concatenated Queue: ");
    display(&q1);
}
