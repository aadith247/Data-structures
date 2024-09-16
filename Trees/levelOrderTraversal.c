#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node* createNode(int d)    //store the root in the queue and store the null in the second place....
{
    struct node *t=malloc(sizeof(struct node ));  // while dequeuing The root is stored in the queue..if the left is there then enqueue it
    t->data=d;
    t->right=NULL;   //Else if the left is not there check for right...then enqueue right root....
    t->left=NULL;    //As soon as the null appears, then print the next line and enqueue it....
    return t;        //Watch the striver video for good concept revision of this level order traversal

}

struct queue {
    struct node *root;
    struct queue *next; // Corrected member name
};

struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue(struct node *root) {
    struct queue *new = malloc(sizeof(struct queue));
    new->root = root;
    new->next = NULL;
    if (front == NULL) {
        front = new;
        rear = new; // Corrected variable name
    } else {
        rear->next = new;
        rear = new; // Corrected variable name
    }
}
int empty() {
    
    return front == NULL;
}
struct node *dequeue() {
    if (!empty()) {
        struct node *r = front->root;
        front = front->next;
        return r;
    } else {
        return NULL; // Return NULL instead of 0
    }
}



int main() {
    struct node *root = createNode(50);
    root->left = createNode(45);
    root->left->left = createNode(40);
    root->left->left->left = createNode(30);
    root->left->left->right = createNode(41);
    root->left->right = createNode(46);

    root->right = createNode(55);
    root->right->left = createNode(53);
    root->right->left->left = createNode(52);
    root->right->left->right = createNode(54);
    root->right->right = createNode(56);

    enqueue(root);
    enqueue(NULL);
    while (!empty()) {
        struct node *h = dequeue(); // Declare h here
        if (h == NULL) {
            printf("\n");
            if (!empty()) // Avoid enqueuing NULL again if the queue is empty
                enqueue(NULL);
        } else {
            printf("%d ", h->data);
            if (h->left != NULL)
                enqueue(h->left);
            if (h->right != NULL)
                enqueue(h->right);
        }
    }
}
