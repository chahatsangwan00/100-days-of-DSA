#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

    struct Node *slow = head;
    struct Node *fast = head;
    bool hasCycle = false;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
        {
            hasCycle = true;
            break;
        }
    }

    if(hasCycle)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}