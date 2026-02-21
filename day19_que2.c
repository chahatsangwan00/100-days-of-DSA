#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    int totalSum = 0;
    int maxSum = nums[0], currMax = nums[0];
    int minSum = nums[0], currMin = nums[0];

    totalSum = nums[0];

    for(int i = 1; i < n; i++)
    {
        if(currMax + nums[i] > nums[i])
            currMax = currMax + nums[i];
        else
            currMax = nums[i];

        if(currMax > maxSum)
            maxSum = currMax;

        if(currMin + nums[i] < nums[i])
            currMin = currMin + nums[i];
        else
            currMin = nums[i];

        if(currMin < minSum)
            minSum = currMin;

        totalSum += nums[i];
    }

    if(maxSum < 0)
        printf("%d\n", maxSum);
    else
    {
        int circularMax = totalSum - minSum;
        if(circularMax > maxSum)
            printf("%d\n", circularMax);
        else
            printf("%d\n", maxSum);
    }

    return 0;
}