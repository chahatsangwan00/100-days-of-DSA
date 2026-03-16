#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    int min;
    struct Node* next;
};

struct Node* topNode = NULL;

void push(int val)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;

    if(topNode == NULL)
        newNode->min = val;
    else
        newNode->min = (val < topNode->min) ? val : topNode->min;

    newNode->next = topNode;
    topNode = newNode;
}

void pop()
{
    if(topNode == NULL)
        return;

    struct Node* temp = topNode;
    topNode = topNode->next;
    free(temp);
}

int top()
{
    if(topNode == NULL)
        return -1;

    return topNode->val;
}

int getMin()
{
    if(topNode == NULL)
        return -1;

    return topNode->min;
}

int main()
{
    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++)
    {
        int op;
        scanf("%d", &op);

        if(op == 1)
        {
            int val;
            scanf("%d", &val);
            push(val);
        }
        else if(op == 2)
        {
            pop();
        }
        else if(op == 3)
        {
            printf("%d\n", top());
        }
        else if(op == 4)
        {
            printf("%d\n", getMin());
        }
    }

    return 0;
}