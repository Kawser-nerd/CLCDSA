#include<stdio.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    char s[102];
    scanf("%s", s);
    int i, j;
    int l = -1;
    for (i = 0; i < n; i++)
        if (s[i] == '.')
            l = i + 1;
    if (l == -1)
    {
        printf("0\n");
        return 0;
    }
    int ans = 0, x = 0;
    for (i = 0; i < l - r; i++)
    {
        if (s[i] == '.')
        {
            ans += x;
            ans++;
            for (j = i; j < min(n, r + i); j++)
                s[j] = 'o';
            x = 0;
        }
        x++;
    }
    ans += x;
    ans++;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &r);
     ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^