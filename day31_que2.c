#include <stdio.h>
#include <string.h>

int main()
{
    char s[10005];
    scanf("%s", s);

    char stack[10005];
    int top = -1;
    int valid = 1;

    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            stack[++top] = s[i];
        }
        else
        {
            if(top == -1)
            {
                valid = 0;
                break;
            }

            char open = stack[top--];

            if((s[i] == ')' && open != '(') ||
               (s[i] == '}' && open != '{') ||
               (s[i] == ']' && open != '['))
            {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;

    if(valid)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}