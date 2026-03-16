#include <stdio.h>
#include <string.h>

int deque[1000];
int front = -1;
int rear = -1;

int empty()
{
    if(front==-1)
        return 1;
    return 0;
}

int size()
{
    if(front==-1)
        return 0;
    return rear-front+1;
}

void push_front(int x)
{
    if(front==-1)
    {
        front=rear=0;
        deque[front]=x;
    }
    else
    {
        for(int i=rear;i>=front;i--)
            deque[i+1]=deque[i];
        deque[front]=x;
        rear++;
    }
}

void push_back(int x)
{
    if(front==-1)
    {
        front=rear=0;
        deque[rear]=x;
    }
    else
    {
        rear++;
        deque[rear]=x;
    }
}

void pop_front()
{
    if(empty())
        return;
    if(front==rear)
        front=rear=-1;
    else
        front++;
}

void pop_back()
{
    if(empty())
        return;
    if(front==rear)
        front=rear=-1;
    else
        rear--;
}

int get_front()
{
    if(empty())
        return -1;
    return deque[front];
}

int get_back()
{
    if(empty())
        return -1;
    return deque[rear];
}

void display()
{
    for(int i=front;i<=rear;i++)
        printf("%d ",deque[i]);
}

int main()
{
    int n,x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"push_front")==0)
        {
            scanf("%d",&x);
            push_front(x);
        }
        else if(strcmp(op,"push_back")==0)
        {
            scanf("%d",&x);
            push_back(x);
        }
        else if(strcmp(op,"pop_front")==0)
        {
            pop_front();
        }
        else if(strcmp(op,"pop_back")==0)
        {
            pop_back();
        }
        else if(strcmp(op,"front")==0)
        {
            printf("%d\n",get_front());
        }
        else if(strcmp(op,"back")==0)
        {
            printf("%d\n",get_back());
        }
        else if(strcmp(op,"size")==0)
        {
            printf("%d\n",size());
        }
        else if(strcmp(op,"empty")==0)
        {
            printf("%d\n",empty());
        }
    }

    display();

    return 0;
}