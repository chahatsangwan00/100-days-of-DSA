#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);

    int nums[100000];

    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    scanf("%d",&k);

    for(int i=0;i<=n-k;i++)
    {
        int max = nums[i];

        for(int j=i;j<i+k;j++)
        {
            if(nums[j] > max)
                max = nums[j];
        }

        printf("%d ",max);
    }

    return 0;
}