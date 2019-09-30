#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char s[100005];
    scanf("%s", s);
    int n = strlen(s);
    int i;
    int t;
    scanf("%d", &t);
    int l, r, u, d, a;
    l = r = u = d = a = 0;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'L')l++;
        if (s[i] == 'R')r++;
        if (s[i] == 'U')u++;
        if (s[i] == 'D')d++;
        if (s[i] == '?')a++;
    }
    int x, y;
    x = abs(l - r);
    y = abs(u - d);
    int ans[2];
    ans[0] = x + y + a;
    ans[1] = x + y - a;
    if (ans[1] < 0)
    {
        ans[1] *= -1;
        ans[1] %= 2;
    }
    t--;
    printf("%d\n", ans[t]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:9: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
     x = abs(l - r);
         ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &t);
     ^