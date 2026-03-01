#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    struct Node *nodes[n];

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        nodes[i] = newNode;

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    int pos;
    scanf("%d", &pos);

    if(pos >= 0 && pos < n)
        temp->next = nodes[pos];

    struct Node *slow = head, *fast = head;
    int hasCycle = 0;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            hasCycle = 1;
            break;
        }
    }

    if(!hasCycle)
    {
        printf("no cycle\n");
        return 0;
    }

    slow = head;
    int index = 0;

    while(slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
        index++;
    }

    printf("tail connects to node index %d\n", index);

    return 0;
}