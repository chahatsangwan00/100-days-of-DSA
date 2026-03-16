#include <stdio.h>

int main()
{
    int n,m;
    scanf("%d",&m);

    char tasks[10000];
    for(int i=0;i<m;i++)
        scanf(" %c",&tasks[i]);

    scanf("%d",&n);

    int freq[26]={0};

    for(int i=0;i<m;i++)
        freq[tasks[i]-'A']++;

    int max=0,count=0;

    for(int i=0;i<26;i++)
    {
        if(freq[i]>max)
            max=freq[i];
    }

    for(int i=0;i<26;i++)
    {
        if(freq[i]==max)
            count++;
    }

    int part=(max-1)*(n+1)+count;

    if(part<m)
        printf("%d",m);
    else
        printf("%d",part);

    return 0;
}