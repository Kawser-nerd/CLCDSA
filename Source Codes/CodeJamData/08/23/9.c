#include <stdio.h>
#include <string.h>
int idx[10001], num[10001];
int main()
{
    int tc, cn;
    int i, j, k, n;
    int cur;
    int q[10001];
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d", &k);
        memset(idx, 0, sizeof(idx)); 
        idx[1] = 1;
        cur = 1;
        for (i = 2; i <= k; i++) {
            for (j = 0; j < i; j++) {
                cur++;
                if (cur == k+1)
                    cur = 1;
                while (idx[cur] != 0) {
                    cur++;
                    if (cur == k+1)
                        cur = 1;
                }
            }
            idx[cur] = i;
        }
        for (i = 1; i <= k; i++) {
            num[i] = idx[i];
        }
        scanf("%d", &n);
        printf("Case #%d:", cn);
        for (i = 0; i < n; i++) {
            scanf("%d", &j);
            printf(" %d", num[j]);
        }
        printf("\n");
    }
    return 0;
}
