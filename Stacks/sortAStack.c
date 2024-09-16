#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int temp[MAX];
int top1=-1;
int top2=-1;

int n=5;
int arr[5];


int pop1()
{
     int t;
     if(top1!=-1)
       {
        t=stack[top1];
  top1=top1-1;
  return t;
    }
}
int pop2()
{
     int t;
     if(top2!=-1)
       {
        t=temp[top2];
  top2=top2-1;
  return t;
    }
}
void push2(int s)
{
    if(top2!=MAX-1)
    {
        top2=top2+1;
        temp[top2]=s;
    }
}
void push1(int s)
{
    if(top1!=MAX-1)
    {
        top1=top1+1;
        stack[top1]=s;
    }
}


void sort()
{
    while(top1!=-1)
    {
        int x=pop1();
        if(top2==-1)
        {
            push2(x);

        } else {
            if(x<temp[top2])
            {
                while(x<temp[top2] || top2!=-1)
                {
                    int y=pop2();
                    push1(y);
                }
                push2(x);

            } else if(x>temp[top2])
            {
                push2(x);
            }


        }
    }
    

}
void printlist(){
    while(top2!=-1)
    {
        printf(" %d",pop2());
    }
}






int main()
{


    printf("Enter the array please..");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        push1(arr[i]);
    }
    sort();
    printlist();


}
