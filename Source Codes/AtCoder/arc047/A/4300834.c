#include<stdio.h>
int main()
{
    int n, l;
    scanf("%d %d", &n, &l);
    int i;
    char  s[100005];
    scanf("%s", s);
    int ans = 0;
    int p = 1;
    for (i = 0; i < n; i++)
    {
        if (s[i] == '+')
            p++;
        else
            p--;
        if (p > l)
        {
            ans++;
            p = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &l);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^