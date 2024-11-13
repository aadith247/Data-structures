// check whether ll is pallindrome or not

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

int checkPallindrome(struct node *head){
    if(head==NULL||head->link==NULL){
        return 1;
    }
    else{
        struct node *temp = head;
        int i=0,n=0;
        while(temp!=NULL){
            temp=temp->link;
            n++;
        }
        temp=head;
        int A[n];
        while(temp!=NULL){
            A[i]=temp->data;
            temp=temp->link;
            i++;
        }
        for(int j=0;j<n/2;j++){
            if(A[j]!=A[n-j-1]){
                return 0;
            }
        }
        return 1;
    }
}
int main (){

    info();
    struct node *head;
    int n;
    printf("Enter number of nodes...");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter data...");
        int item;
        scanf("%d",&item);
        head=input(head,item);
    }
    printf("Enterd link list...\n");
    output(head);

    if(checkPallindrome(head)){
        printf("Entered linked list is pallindrome.\n");
    }
    else{
        printf("Enterd linked list isn't a pallindrome.\n");
    }
    return 0;
}
