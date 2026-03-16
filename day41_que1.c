#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;

    if(rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

int dequeue()
{
    if(front==NULL)
        return -1;

    struct node *temp=front;
    int x=temp->data;
    front=front->next;

    if(front==NULL)
        rear=NULL;

    free(temp);
    return x;
}

int main()
{
    int n,x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%s",op);

        if(strcmp(op,"enqueue")==0)
        {
            scanf("%d",&x);
            enqueue(x);
        }
        else if(strcmp(op,"dequeue")==0)
        {
            printf("%d\n",dequeue());
        }
    }

    return 0;
}