#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld", &n);

    long long arr[n];
    long long sum = 0;

    for(long long i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }

    long long total = (n + 1) * (n + 2) / 2;
    long long missing = total - sum;

    printf("%lld\n", missing);

    return 0;
}

