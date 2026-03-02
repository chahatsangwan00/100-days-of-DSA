#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

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

    return head;
}

struct Node* reverse(struct Node* head)
{
    struct Node *prev = NULL, *curr = head, *nextNode = NULL;

    while(curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

int main()
{
    int n1, n2;
    scanf("%d", &n1);
    struct Node* l1 = createList(n1);

    scanf("%d", &n2);
    struct Node* l2 = createList(n2);

    l1 = reverse(l1);
    l2 = reverse(l2);

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    int carry = 0;

    while(l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if(l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if(l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;

        carry = sum / 10;
    }

    struct Node* result = reverse(dummy.next);

    while(result != NULL)
    {
        printf("%d ", result->data);
        result = result->next;
    }

    return 0;
}