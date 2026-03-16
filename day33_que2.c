#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[10000];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int n,i,a,b;
    scanf("%d",&n);

    char token[20];

    for(i=0;i<n;i++)
    {
        scanf("%s",token);

        if(strcmp(token,"+")==0)
        {
            b = pop();
            a = pop();
            push(a+b);
        }
        else if(strcmp(token,"-")==0)
        {
            b = pop();
            a = pop();
            push(a-b);
        }
        else if(strcmp(token,"*")==0)
        {
            b = pop();
            a = pop();
            push(a*b);
        }
        else if(strcmp(token,"/")==0)
        {
            b = pop();
            a = pop();
            push(a/b);
        }
        else
        {
            push(atoi(token));
        }
    }

    printf("%d",pop());

    return 0;
}