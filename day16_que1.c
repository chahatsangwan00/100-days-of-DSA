#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    if(n <= 0)
        return 0;

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int count = 1;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] == arr[i - 1])
        {
            count++;
        }
        else
        {
            printf("%d:%d ", arr[i - 1], count);
            count = 1;
        }
    }

    printf("%d:%d", arr[n - 1], count);

    return 0;
}
