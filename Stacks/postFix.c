#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
char str[MAX];
int top=-1;

int pop()
{
     int t; 
        t=stack[top];
  top=top-1;
  return t;
    }

void push(int s)
{
  
    
        top=top+1;
        stack[top]=s;
    
}
void postfix()
{
    for(int i=0;i<strlen(str);i++)
    {
        
        if(str[i]=='*'||str[i]=='+'||str[i]=='-'||str[i]=='/')
        {
             char option=str[i];
            int a=pop();
            int b=pop();
           
            switch(option)
            {
                case '+':
                push(a + b);
                break;
                case '-':
                push(b - a);
                break;
                case '*':
                push(b * a);
                break;
                case '/':
                push(b/a);
                break;
            }
        }  else {
            push(str[i] - '0'); // typecasted the char to integer using ascii gnanam...
        }

    }
    printf("%d",stack[top]);
    
}


int main()
{
    printf("Enter the string.....");
    scanf("%s",str);
    postfix();
}

 