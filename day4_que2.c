#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int val;
    scanf("%d", &val);

    int k = 0;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] != val)
        {
            nums[k] = nums[i];
            k++;
        }
    }

    printf("%d\n", k);

    for(int i = 0; i < k; i++)
    {
        printf("%d ", nums[i]);
    }

    return 0;
}
