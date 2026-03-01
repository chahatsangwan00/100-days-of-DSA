#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

struct MyLinkedList
{
    struct Node* head;
    int size;
};

struct MyLinkedList* myLinkedListCreate()
{
    struct MyLinkedList* obj = (struct MyLinkedList*)malloc(sizeof(struct MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}

int myLinkedListGet(struct MyLinkedList* obj, int index)
{
    if(index < 0 || index >= obj->size)
        return -1;

    struct Node* temp = obj->head;
    for(int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void myLinkedListAddAtHead(struct MyLinkedList* obj, int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}

void myLinkedListAddAtTail(struct MyLinkedList* obj, int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;

    if(obj->head == NULL)
    {
        obj->head = node;
    }
    else
    {
        struct Node* temp = obj->head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
    obj->size++;
}

void myLinkedListAddAtIndex(struct MyLinkedList* obj, int index, int val)
{
    if(index < 0 || index > obj->size)
        return;

    if(index == 0)
    {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;

    struct Node* temp = obj->head;
    for(int i = 0; i < index - 1; i++)
        temp = temp->next;

    node->next = temp->next;
    temp->next = node;
    obj->size++;
}

void myLinkedListDeleteAtIndex(struct MyLinkedList* obj, int index)
{
    if(index < 0 || index >= obj->size)
        return;

    struct Node* temp = obj->head;

    if(index == 0)
    {
        obj->head = temp->next;
        free(temp);
    }
    else
    {
        for(int i = 0; i < index - 1; i++)
            temp = temp->next;

        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }
    obj->size--;
}