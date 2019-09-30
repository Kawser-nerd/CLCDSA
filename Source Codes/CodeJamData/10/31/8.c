#include <stdio.h>
#include <string.h>
typedef struct _d {
    int a, b;
} DATA;
DATA data[1011];
int n;
char check[10011];
int comp(const void* x, const void* y)
{
    DATA* a = (DATA*)x;
    DATA* b = (DATA*)y;
    return a->a - b->a;
}
int main()
{
    int tc, cn;
    int i, j, k;
    long long cnt;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d%d", &data[i].a, &data[i].b);
        }
        cnt = 0;
        if (n == 1) {
            printf("Case #%d: %d\n", cn, 0);
            continue;
        }
        qsort(data, n, sizeof(DATA), comp);
        memset(check, 0, sizeof(check));
        for (i = 0; i < n; i++) {
            k = data[i].b;
            for (j = k+1; j <= 10000; j++) {
                if (check[j])
                    cnt++;
            }
            check[k] = 1;
        }
        printf("Case #%d: %I64d\n", cn, cnt);
    }
    return 0;
}
