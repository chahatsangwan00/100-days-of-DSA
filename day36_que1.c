#include <stdio.h>

int queue[100];
int front = 0;
int rear = -1;
int size = 100;

void enqueue(int x)
{
    rear = (rear + 1) % size;
    queue[rear] = x;
}

void dequeue()
{
    front = (front + 1) % size;
}

void display()
{
    int i = front;
    while(1)
    {
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main()
{
    int n,m,i,x;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        dequeue();
    }

    display();

    return 0;
}