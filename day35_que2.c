#include <stdio.h>

int s1[100], s2[100];
int top1 = -1, top2 = -1;

void push1(int x)
{
    s1[++top1] = x;
}

int pop1()
{
    return s1[top1--];
}

void push2(int x)
{
    s2[++top2] = x;
}

int pop2()
{
    return s2[top2--];
}

void push(int x)
{
    push1(x);
}

int pop()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            push2(pop1());
        }
    }
    return pop2();
}

int peek()
{
    if(top2 == -1)
    {
        while(top1 != -1)
        {
            push2(pop1());
        }
    }
    return s2[top2];
}

int empty()
{
    if(top1 == -1 && top2 == -1)
        return 1;
    else
        return 0;
}

int main()
{
    push(1);
    push(2);
    printf("%d\n",peek());
    printf("%d\n",pop());
    printf("%d\n",empty());
    return 0;
}