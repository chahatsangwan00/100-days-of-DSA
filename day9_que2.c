#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    char s[n];

    for(int i = 0; i < n; i++)
    {
        scanf(" %c", &s[i]);
    }

    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        left++;
        right--;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%c ", s[i]);
    }

    return 0;
}
