#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int stack[1000];
    int top = -1;

    for(int i = 0; i < n; i++)
    {
        int type;
        scanf("%d", &type);

        if(type == 1)
        {
            int value;
            scanf("%d", &value);
            stack[++top] = value;
        }
        else if(type == 2)
        {
            if(top == -1)
                printf("Stack Underflow\n");
            else
                printf("%d\n", stack[top--]);
        }
        else if(type == 3)
        {
            for(int j = top; j >= 0; j--)
                printf("%d ", stack[j]);
            printf("\n");
        }
    }

    return 0;
}