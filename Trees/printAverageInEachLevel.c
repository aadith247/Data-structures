//I am going to use level order traversal to do this problem...
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

void  levelAverage(struct node *root)
{
    enqueue(root);
    enqueue(NULL);
     int sum=0;
      int count=0;
    while(!empty())
    {
        struct node *cur=dequeue();

        
        if(cur!=NULL)
        {
            
            sum+=cur->data;
            count++;
        
        
        if(cur->left!=NULL)
        {
            enqueue(cur->left);
        } 
        if(cur->right!=NULL)
        {
            enqueue(cur->right);
                    }
        }
        else if(cur==NULL) {  //This was missing....
            
            if (count > 0) {
                printf(" %d ", sum / count);
            }
            printf("\n");
            sum = 0;
            count = 0;
            if (!empty()) {
                enqueue(NULL);
            }
        }
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
    levelAverage(root);
}
