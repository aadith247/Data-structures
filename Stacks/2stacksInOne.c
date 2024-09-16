#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
int  stack[MAX];
int top1=-1;
int top2=MAX/2;

int full()
{
    if(top1==MAX/2-1)
    {
        return 1;
    } else {
        return 0;
    }
}

int full2()
{
    if(top2==MAX-1)
    {
        return 1;
    } else {
        return 0;
    }
}

int isempty1()
{
    if(top1==-1)
    {
        return 1;
    }else {
        return 0;
    }
}

int isempty2()
{
    if(top2==MAX/2)
    {
        return 1;
    } else {
        return 0;
    }
}


int pop1()
{
    if(!isempty1())
    {
        int t=stack[top1];
        top1--;
        printf("You removed %d from stack 1",t);
        return t;
        
    } else {
        printf("The stack 1 is empty...");
        return 1;
    }
}
int pop2()
{
    if(!isempty2())
    {
        int g=stack[top2];
        top2--;
        printf("You removed %d from stack 2",g); 
        return g;

    } else {
        printf("The stack 2 is empty....");
        return 1;
    }
}
void push1(int data)
{
   
    if(!full())
    {
         top1+=1;
    stack[top1]=data;
    printf("You Inserted %d in stack1",data);
    printf("\n");
    } else {
        printf("the stack 1 is overflow.....");
        printf("\n");
    }

}
void push2(int data)
{
    if(!full2())
    {
        top2+=1;
        stack[top2]=data;
        printf("You inserted %d in stack 2",data);
        printf("\n");
    } else {
        printf("The stack 2 is overflown");
        printf("\n");

    }


}

int main()

{
    push1(90);
    push1(23);
    push2(89);
    push2(2);
    push2(12);
    pop1();
    pop2();

}
