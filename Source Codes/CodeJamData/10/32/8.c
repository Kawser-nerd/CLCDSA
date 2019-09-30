#include <stdio.h>
#include <string.h>
int main()
{
    int tc, cn;
    int i, j, k;
    int l, p, c;
    int cnt, cnt2;
    long long temp;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d%d%d", &l, &p, &c);
        temp = l;
        cnt = -1;
        while (temp < p) {
            temp = temp * (long long)c;
            cnt++;
        }
        cnt2 = 0;
        while (cnt > 0) {
            cnt /= 2;
            cnt2++;
        }
        printf("Case #%d: %d\n", cn, cnt2);
    }
    return 0;
}
