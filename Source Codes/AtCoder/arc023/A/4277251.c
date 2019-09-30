#include<stdio.h>
int main()
{
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (m < 3)
    {
        m += 12;
        y--;
    }
    int ans = 0;
    ans += 365 * y + y / 4;
    ans += y / 400 - y / 100;
    ans += (306 * (m + 1)) / 10;
    ans += d - 429;
    ans = 735369 - ans;
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &y, &m, &d);
     ^