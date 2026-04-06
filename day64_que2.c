#include <stdio.h>

struct Cell
{
    int x;
    int y;
    int time;
};

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int grid[m][n];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &grid[i][j]);
    }

    struct Cell queue[m*n];
    int front = 0, rear = 0;

    int fresh = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 2)
            {
                queue[rear].x = i;
                queue[rear].y = j;
                queue[rear].time = 0;
                rear++;
            }
            else if(grid[i][j] == 1)
                fresh++;
        }
    }

    int maxTime = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while(front < rear)
    {
        struct Cell curr = queue[front++];
        int x = curr.x;
        int y = curr.y;
        int t = curr.time;

        if(t > maxTime)
            maxTime = t;

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1)
            {
                grid[nx][ny] = 2;
                fresh--;

                queue[rear].x = nx;
                queue[rear].y = ny;
                queue[rear].time = t + 1;
                rear++;
            }
        }
    }

    if(fresh > 0)
        printf("-1");
    else
        printf("%d", maxTime);

    return 0;
}