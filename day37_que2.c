#include <stdio.h>

int arr[10000];
int n = 0;
int k;

void insert(int x)
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

int add(int val)
{
    insert(val);
    return arr[n-k];
}

int main()
{
    int m,i,x;

    scanf("%d",&k);
    scanf("%d",&m);

    for(i=0;i<m;i++)
    {
        scanf("%d",&x);
        insert(x);
    }

    int q;
    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%d",&x);
        printf("%d\n",add(x));
    }

    return 0;
}