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

int dfs(struct Node* adj[], int visited[], int v, int parent)
{
    visited[v] = 1;

    struct Node* temp = adj[v];

    while(temp != NULL)
    {
        int neighbor = temp->data;

        if(visited[neighbor] == 0)
        {
            if(dfs(adj, visited, neighbor, v))
                return 1;
        }
        else if(neighbor != parent)
            return 1;

        temp = temp->next;
    }

    return 0;
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

    int visited[n];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int cycle = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(dfs(adj, visited, i, -1))
            {
                cycle = 1;
                break;
            }
        }
    }

    if(cycle)
        printf("YES");
    else
        printf("NO");

    return 0;
}