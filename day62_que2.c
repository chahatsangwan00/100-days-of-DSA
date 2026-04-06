#include <stdio.h>
#include <stdlib.h>

void dfs(int n, int **rooms, int *sizes, int *visited, int room)
{
    visited[room] = 1;

    for(int i = 0; i < sizes[room]; i++)
    {
        int next = rooms[room][i];

        if(visited[next] == 0)
            dfs(n, rooms, sizes, visited, next);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int **rooms = (int**)malloc(n * sizeof(int*));
    int *sizes = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &sizes[i]);

        rooms[i] = (int*)malloc(sizes[i] * sizeof(int));

        for(int j = 0; j < sizes[i]; j++)
            scanf("%d", &rooms[i][j]);
    }

    int *visited = (int*)calloc(n, sizeof(int));

    dfs(n, rooms, sizes, visited, 0);

    int flag = 1;

    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("true");
    else
        printf("false");

    return 0;
}