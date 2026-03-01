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

    struct Node *slow = head, *fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node *prev = NULL, *curr = slow, *nextNode = NULL;

    while(curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    struct Node *first = head;
    struct Node *second = prev;

    bool isPalindrome = true;

    while(second != NULL)
    {
        if(first->data != second->data)
        {
            isPalindrome = false;
            break;
        }
        first = first->next;
        second = second->next;
    }

    if(isPalindrome)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}