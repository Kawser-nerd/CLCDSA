#include <stdio.h>

#define DATE(y, m, d) (365*y + y/4 - y/100 + y/400 + 306*(m+1)/10 + d - 429)

void solve(int y, int m, int d) {
    if(m == 1 || m == 2) { --y; m += 12; }
    int ans = DATE(2014, 5, 17) - DATE(y, m, d);
    printf("%d\n", ans);
}

int main()
{
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    solve(y, m, d);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &y, &m, &d);
     ^