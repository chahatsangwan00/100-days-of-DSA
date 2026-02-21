#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    long long count = 0;

    for(int i = 0; i < n; i++)
    {
        long long sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            if(sum == 0)
                count++;
        }
    }

    printf("%lld\n", count);

    return 0;
}