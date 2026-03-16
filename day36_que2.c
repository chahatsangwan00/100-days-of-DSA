#include <stdio.h>

int deque[1000];
int front = -1, rear = -1, k;

int isFull()
{
    if((front==0 && rear==k-1) || (rear+1)%k==front)
        return 1;
    return 0;
}

int isEmpty()
{
    if(front==-1)
        return 1;
    return 0;
}

int insertFront(int x)
{
    if(isFull())
        return 0;

    if(front==-1)
    {
        front = rear = 0;
    }
    else if(front==0)
    {
        front = k-1;
    }
    else
    {
        front--;
    }

    deque[front] = x;
    return 1;
}

int insertLast(int x)
{
    if(isFull())
        return 0;

    if(front==-1)
    {
        front = rear = 0;
    }
    else if(rear==k-1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    deque[rear] = x;
    return 1;
}

int deleteFront()
{
    if(isEmpty())
        return 0;

    if(front==rear)
    {
        front = rear = -1;
    }
    else if(front==k-1)
    {
        front = 0;
    }
    else
    {
        front++;
    }

    return 1;
}

int deleteLast()
{
    if(isEmpty())
        return 0;

    if(front==rear)
    {
        front = rear = -1;
    }
    else if(rear==0)
    {
        rear = k-1;
    }
    else
    {
        rear--;
    }

    return 1;
}

int getFront()
{
    if(isEmpty())
        return -1;
    return deque[front];
}

int getRear()
{
    if(isEmpty())
        return -1;
    return deque[rear];
}

int main()
{
    k = 3;

    insertLast(1);
    insertLast(2);
    insertFront(3);
    printf("%d\n", insertFront(4));
    printf("%d\n", getRear());
    printf("%d\n", isFull());
    deleteLast();
    insertFront(4);
    printf("%d\n", getFront());

    return 0;
}