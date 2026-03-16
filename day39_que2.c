#include <stdio.h>

int main()
{
    int n,k;
    scanf("%d",&n);

    int nums[100000];
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);

    scanf("%d",&k);

    int freq[20001]={0};

    for(int i=0;i<n;i++)
        freq[nums[i]+10000]++;

    for(int i=0;i<k;i++)
    {
        int max=0,idx=0;

        for(int j=0;j<20001;j++)
        {
            if(freq[j]>max)
            {
                max=freq[j];
                idx=j;
            }
        }

        printf("%d ",idx-10000);
        freq[idx]=0;
    }

    return 0;
}
