#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
char  stack[MAX];
char str[MAX];
int top=-1;


char pop()
{
     char t;
     if(top!=-1)
       {
        t=stack[top];
  top=top-1;
  return t;
    } else 
    {
        return 0;
    }
}
void push(char s)
{
    if(top!=MAX-1)
    {
        top=top+1;
        stack[top]=s;
    }
}
void reverse()
{
    int i;
    for(int i=0;i<=strlen(str);i++)
    {
        push(str[i]);
    }
    while(top!=-1)
    {
        printf("%c ",pop());
    }
    printf("\n");


}


int main()
{
    printf("Enter the string :  \n ");
    fgets(str,sizeof(str),stdin);
    reverse();
}