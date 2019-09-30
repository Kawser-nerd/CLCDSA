#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, u, n, a[1000], b[1000], s, i, j;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int c[1000] = {};
        printf("Case #%d: ", u);
        scanf("%d", &n);
        for (i = 0 ; i < n ; ++i)
            scanf("%d%d", a + i, b + i);
        for (i = s = 0 ; s < n * 2 ; ++i){
            for (j = 0 ; j < n ; ++j){
                if (c[j] < 2 && b[j] <= s){
                   s += 2 - c[j];
                   c[j] = 2;
                   //printf("2: %d %d\n", j, s);
                   break;
                }
            }
            if (j < n)continue;
            int m = -1, mj;
            for (j = 0 ; j < n ; ++j){
                if (!c[j] && a[j] <= s && b[j] > m){
                   m = b[j], mj = j;
                }
            }
            if (m == -1)break;
            ++s;
            c[mj] = 1;
            //printf("1: %d %d\n", mj, s);
        }
        if (s < n * 2)puts("Too Bad");
        else printf("%d\n", i);
    }
    return 0;
}
