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
    t=stack[top];
  top=top-1;
  return t;
    }

void push(char s)
{
    if(top!=MAX-1)
    {
        top=top+1;
        stack[top]=s;
    }
}
int check(char s)
{
           char a=pop();
            char option=s;
            switch(option)
            {
                case ']':
                if(a=='{'||a=='(')
                {
                    return 0;

                } else {return 1;}
                break;
                case '}':
                if(a=='['|| a=='(')
                {
                    return 0;
                } else {
                    return 1;
                }
                break;
                case ')':
                if(a=='['|| a=='{')
                {
                    return 0;
                } else {
                    return 1;
                }
                break;
                default:
                printf("Happy Journey Brother");

            }

}
void bala()
{ int m=4;
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='['|| str[i]=='{'|| str[i]=='(')
        {
            push(str[i]);

        } else if(str[i]==']'||str[i]=='}' || str[i]==')')
        {
            if(!check(str[i]))
            {
                printf("The Given string is not balanced");
                exit(1);
                break;

            } 
        }
        
    }
    if(top!=-1)
    {
        printf("The string is not balanced");
    } else {
        if(top==-1)
        {
            printf("the string is balanced");
        }
    }
   
}

int main()
{
    printf("Type The String...");
    scanf("%s",str);
    bala();
}