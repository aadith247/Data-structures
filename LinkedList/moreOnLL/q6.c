// merge two sorted singly linked lists
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
    struct node *link;
};

struct node* input(struct node *head, int item){
    struct node *temp=malloc(sizeof(struct node));
    temp->data=item;
    if(head==NULL){
        temp->link=NULL;
    }
    else{
    temp->link=head;
    }
    return temp;
}

void output(struct node *temp){
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->link;
    }
    printf("\n");
    return;
}

struct node *sort(struct node *head){
    struct node *temp=NULL;
    struct node *ptr=NULL;
    for(temp=head;temp->link!=NULL;temp=temp->link){
        for(ptr=temp->link;ptr!=NULL;ptr=ptr->link){
            if(temp->data>ptr->data){
                int a = temp->data;
                temp->data=ptr->data;
                ptr->data=a;
            }
        }
    }
    return head;
}

struct node *merge(struct node *head1, struct node *head2){
    struct node *temp=head1;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=head2;
    head1 = sort(head1);
    return head1;
}
int main (){

    info();
    struct node *head1=NULL;
    int n;
    printf("Enter number of nodes in 1st linked list...");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data...");
        int item;
        scanf("%d",&item);
        head1=input(head1,item);
    }
    printf("1st linked list...\n");
    output(head1);

    head1 = sort(head1);
    printf("1st linked list after sorting...\n");
    output(head1);
    printf("\n\n");
    struct node *head2=NULL;
    int n2;
    printf("Enter number of nodes in 2nd linked list...");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        printf("Enter data...");
        int item;
        scanf("%d",&item);
        head2=input(head2,item);
    }
    printf("2nd linked list...\n");
    output(head2);

    head2 = sort(head2);
    printf("2nd linked list after sorting...\n");
    output(head2);

    head1 = merge(head1, head2);
    printf("\nAfter merging 2 sorted linked list and even sorting them after that output is...\n");
    output(head1);
    
    return 0;
}
