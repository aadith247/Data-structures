// Delete all the odd numbers in a ll.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void info(){
	time_t t;
	time(&t);
	printf("Harshit Srivastava\nBT23CSH051\n\n%s\n",ctime(&t));
	return;
}

struct node{
    int data;
    struct node* link;
};

void output(struct node *temp){
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

struct node* insert_beg(struct node* head, int item){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=item;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->link=head;
        head=temp;
    }
    return head;
}

struct node *delOdd(struct node *head) {
    while (head != NULL && head->data % 2 != 0) {
        struct node *temp = head;
        head = head->link;
        free(temp);
    }

    struct node *temp = head;
    while (temp != NULL && temp->link != NULL) {
        if (temp->link->data % 2 != 0) {
            struct node *ptr = temp->link;
            temp->link = temp->link->link;
            free(ptr);
        } else {
            temp = temp->link;
        }
    }
    return head;
}

int main (){
    info();
    struct node *head=NULL;
    int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int item;
        printf("Enter data for node %d...",i+1);
        scanf("%d",&item);
        head = insert_beg(head,item);
    }
    printf("Entered linked list...\n");
    output(head);
    printf("Linked list after deletion of odd numbers...\n");
    head = delOdd(head);
    output(head);
    return 0;
}
