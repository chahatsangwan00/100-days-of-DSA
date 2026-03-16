#include <stdio.h>
#include <ctype.h>

int stack[100000];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char s[300000];
    fgets(s,300000,stdin);

    long num = 0;
    char op = '+';
    int i = 0;

    while(s[i] != '\0')
    {
        if(isdigit(s[i]))
        {
            num = num*10 + (s[i]-'0');
        }

        if((!isdigit(s[i]) && s[i] != ' ') || s[i+1] == '\0')
        {
            if(op == '+')
                push(num);
            else if(op == '-')
                push(-num);
            else if(op == '*')
            {
                int a = pop();
                push(a*num);
            }
            else if(op == '/')
            {
                int a = pop();
                push(a/num);
            }

            op = s[i];
            num = 0;
        }

        i++;
    }

    int result = 0;

    while(top != -1)
    {
        result += pop();
    }

    printf("%d",result);

    return 0;
}