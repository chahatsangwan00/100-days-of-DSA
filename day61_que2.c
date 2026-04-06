#include <stdio.h>

void dfs(int n, int graph[n][n], int visited[], int city)
{
    visited[city] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[city][i] == 1 && visited[i] == 0)
            dfs(n, graph, visited, i);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int graph[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    int visited[n];

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int count = 0;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(n, graph, visited, i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}