#include<stdio.h>
#include<string.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int i;
    char s[102], t[102];
    scanf("%s%s", s, t);
    char x;
    for (i = 0; i < strlen(s) - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            x = s[i];
            s[i] = s[i + 1];
            s[i + 1] = x;
            if (i > 0)
                i -= 2;
        }
    }
    for (i = 0; i < strlen(t) - 1; i++)
    {
        if (t[i] < t[i + 1])
        {
            x = t[i];
            t[i] = t[i + 1];
            t[i + 1] = x;
            if (i > 0)
                i -= 2;
        }
    }
    for (i = 0; i < min(strlen(s), strlen(t)); i++)
    {
        if (s[i] < t[i])
        {
            printf("Yes\n");
            return 0;
        }
        if (s[i] > t[i])
        {
            printf("No\n");
            return 0;
        }
    }
    if (strlen(s) < strlen(t))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s", s, t);
     ^