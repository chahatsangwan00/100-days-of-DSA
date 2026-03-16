#include <stdio.h>

int arr[100000];
int n = 0;

void addNum(int x)
{
    int i = n - 1;
    while(i >= 0 && arr[i] > x)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = x;
    n++;
}

double findMedian()
{
    if(n % 2 == 1)
        return arr[n/2];
    else
        return (arr[n/2] + arr[n/2 - 1]) / 2.0;
}

int main()
{
    int q;
    char op[20];
    int x;

    scanf("%d",&q);

    for(int i=0;i<q;i++)
    {
        scanf("%s",op);

        if(op[0]=='a')
        {
            scanf("%d",&x);
            addNum(x);
        }
        else
        {
            printf("%.1f\n",findMedian());
        }
    }

    return 0;
}