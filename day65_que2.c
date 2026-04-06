#include <stdio.h>

int find(int parent[], int x)
{
    if(parent[x] != x)
        parent[x] = find(parent, parent[x]);
    return parent[x];
}

void unionSet(int parent[], int rank[], int x, int y)
{
    int px = find(parent, x);
    int py = find(parent, y);

    if(px == py)
        return;

    if(rank[px] < rank[py])
        parent[px] = py;
    else if(rank[px] > rank[py])
        parent[py] = px;
    else
    {
        parent[py] = px;
        rank[px]++;
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int edges[E][2];

    for(int i = 0; i < E; i++)
        scanf("%d %d", &edges[i][0], &edges[i][1]);

    int parent[V], rank[V];

    for(int i = 0; i < V; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }

    int cycle = 0;

    for(int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        int pu = find(parent, u);
        int pv = find(parent, v);

        if(pu == pv)
        {
            cycle = 1;
            break;
        }

        unionSet(parent, rank, pu, pv);
    }

    if(cycle)
        printf("true");
    else
        printf("false");

    return 0;
}