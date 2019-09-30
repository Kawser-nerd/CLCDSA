#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct attack{
    int d, w, e, s;
};

int cmp(const void *a, const void *b){
    struct attack x = *(struct attack*)a, y = *(struct attack*)b;
    if (x.d > y.d)return 1;
    if (x.d < y.d)return -1;
    return 0;
}

int main(){
    int t, u;
    scanf("%d", &t);
    for (u = 1 ; u <= t ; ++u){
        int N, i, j, k, l, cnt = 0, ans = 0;
        int wall[401] = {};
        struct attack a[100];
        scanf("%d", &N);
        for (i = 0 ; i < N ; ++i){
            int d, n, w, e, s, dd, dp, ds;
            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            for (j = 0 ; j < n ; ++j, ++cnt){
                a[cnt].d = d + dd * j;
                a[cnt].w = w + dp * j + 200;
                a[cnt].e = e + dp * j + 200;
                a[cnt].s = s + ds * j;
            }
        }
        qsort(a, cnt, sizeof(struct attack), cmp);
        for (i = 0 ; i < cnt ; i = j){
            int nw[401];
            memcpy(nw, wall, sizeof(wall));
            for (j = i + 1 ; j < cnt && a[j].d == a[i].d ; ++j);
            for (k = i ; k < j ; ++k){
                int win = 0;
                for (l = a[k].w ; l < a[k].e ; ++l){
                    if (a[k].s > wall[l])win = 1;
                    if (a[k].s > nw[l])nw[l] = a[k].s;
                }
                ans += win;
            }
            memcpy(wall, nw, sizeof(wall));
        }
        printf("Case #%d: %d\n", u, ans);
    }
    return 0;
}
