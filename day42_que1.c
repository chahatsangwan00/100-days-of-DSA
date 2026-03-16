#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    int queue[1000], stack[1000];
    int front=0,rear=n-1,top=-1;

    for(int i=0;i<n;i++)
        scanf("%d",&queue[i]);

    for(int i=front;i<=rear;i++)
        stack[++top]=queue[i];

    for(int i=front;i<=rear;i++)
        queue[i]=stack[top--];

    for(int i=front;i<=rear;i++)
        printf("%d ",queue[i]);

    return 0;
}