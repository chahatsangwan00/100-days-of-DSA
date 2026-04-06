#include <stdio.h>

void dfs(int m, int n, int image[m][n], int sr, int sc, int oldColor, int newColor)
{
    if(sr < 0 || sc < 0 || sr >= m || sc >= n)
        return;

    if(image[sr][sc] != oldColor)
        return;

    image[sr][sc] = newColor;

    dfs(m, n, image, sr + 1, sc, oldColor, newColor);
    dfs(m, n, image, sr - 1, sc, oldColor, newColor);
    dfs(m, n, image, sr, sc + 1, oldColor, newColor);
    dfs(m, n, image, sr, sc - 1, oldColor, newColor);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    int image[m][n];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            scanf("%d", &image[i][j]);
    }

    int sr, sc, color;
    scanf("%d %d %d", &sr, &sc, &color);

    int oldColor = image[sr][sc];

    if(oldColor != color)
        dfs(m, n, image, sr, sc, oldColor, color);

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d ", image[i][j]);
        printf("\n");
    }

    return 0;
}