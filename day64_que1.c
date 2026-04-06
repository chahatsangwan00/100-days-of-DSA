#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    int n;
    scanf("%d", &n);

    struct Node* adj[n];

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    int m;
    scanf("%d", &m);

    int u, v;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        struct Node* newNode2 = createNode(u);
        newNode2->next = adj[v];
        adj[v] = newNode2;
    }

    int s;
    scanf("%d", &s);

    int visited[n];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;

    while(front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];

        while(temp != NULL)
        {
            if(visited[temp->data] == 0)
            {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }

    return 0;
}