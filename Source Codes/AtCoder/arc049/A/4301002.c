#include<stdio.h>
#include<string.h>
int main()
{
    char s[102];
    scanf("%s", s);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int n = strlen(s);
    s[n] = '\n';
    for (int i = 0; i <= n; i++)
    {
        if (i == a || i == b || i == c || i == d)
            printf("\"");
        printf("%c", s[i]);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d", &a, &b, &c, &d);
     ^