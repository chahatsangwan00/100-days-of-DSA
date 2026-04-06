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

void dfs(struct Node* adj[], int visited[], int v)
{
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        if(visited[temp->data] == 0)
            dfs(adj, visited, temp->data);

        temp = temp->next;
    }
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

    dfs(adj, visited, s);

    return 0;
}