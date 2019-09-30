#include <stdio.h>
#include <string.h>
int m, v;
int inner_node;
int ch[100], org[100], temp[100];
int eval(int u)
{
    int a, b;
    if (u > inner_node)
        return temp[u];
    a = eval(u*2);
    b = eval(u*2 + 1);
    if (temp[u] == 1) {
        if (a == 1 && b == 1)
            return 1;
        return 0;
    }
    if (a == 1 || b == 1)
        return 1;
    return 0;
}
int main()
{
    int tc, cn;
    int i, j, k;
    int a, min1, fl, cnt;
    scanf("%d", &tc);
    for (cn = 1; cn <= tc; cn++) {
        scanf("%d%d", &m, &v);
        inner_node = (m-1) / 2;
        for (i = 1; i <= inner_node; i++) {
            scanf("%d%d", &org[i], &ch[i]);    
        }
        for ( ; i <= m; i++) {
            scanf("%d", &org[i]);
        }
        min1 = 999999999;
        for (i = 0; i < (1 << inner_node); i++) {
            fl = 1;
            cnt = 0;
            for (j = 1; j <= m; j++) {
                temp[j] = org[j];
            }
            for (j = 1, k = 1; j <= i; j *= 2, k++) {
                if (i & j) {
                    if (ch[k] == 0) {
                        fl = 0;
                    }
                    cnt++;
                    if (org[k] == 0)
                        temp[k] = 1;
                    else
                        temp[k] = 0;
                }
            }
            if (fl == 0)
               continue; 
            a = eval(1);
            if (a == v) {
                if (cnt < min1)
                    min1 = cnt;
            }
        }
        printf("Case #%d: ", cn);
        if (min1 == 999999999) {
            printf("IMPOSSIBLE\n");
        }
        else {
            printf("%d\n", min1);
        }
    }
    return 0;
}
