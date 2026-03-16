#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop()
{
    struct node *temp = top;
    int x = temp->data;
    top = top->next;
    free(temp);
    return x;
}

int main()
{
    char token[20];
    int a,b;

    while(scanf("%s",token) != EOF)
    {
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