#include<stdio.h>
#include<stdlib.h>

int main(){
    int t, tt;
    scanf("%d", &t);
    for (tt = 1 ; tt <= t ; ++tt){
        int n, w, l, i, j, x, nowx, nowy, nexty, min = 1, r[1000], m[1000], ax[1000], ay[1000];
        char u[1000] = {};
        scanf("%d%d%d", &n, &w, &l);
        for (i = 0 ; i < n ; ++i){
            scanf("%d", &x);
            for (j = i ; j > 0 ; --j){
                if (r[j - 1] >= x)break;
                r[j] = r[j - 1], m[j] = m[j - 1];
            }
            r[j] = x, m[j] = i;
        }
        //for (i = 0 ; i < n ; ++i)printf("=%d", r[i]);puts("");
        nowx = nexty = r[0], nowy = 0;
        ax[m[0]] = 0, ay[m[0]] = 0;
        while (1){
              for (i = min ; i < n ; ++i){
                  //printf("{%d %d}", i, min);
                  if (!u[i] && nowx + r[i] <= w){
                     ax[m[i]] = nowx + r[i], ay[m[i]] = nowy;
                     //printf("%d: %d %d\n", m[i], ax[m[i]], ay[m[i]]);
                     nowx += r[i] * 2;
                     u[i] = 1;
                     if (i == min)while (min < n && u[min])++min;
                     if (nowx >= w || min == n)break;
                  }
              }
              if (min == n)break;
              nowy = nexty + r[min];
              ax[m[min]] = 0, ay[m[min]] = nowy;
              //printf("%d: %d %d\n", m[i], ax[m[min]], ay[m[min]]);
              if (nowy > l){fprintf(stderr, "Uh oh~ l not enough\n");scanf(" ");}
              nexty = nowy + r[min];
              nowx = r[min];
              u[min] = 1;
              while (min < n && u[min])++min;
              if (min == n)break;
        }
        printf("Case #%d:", tt);
        for (i = 0 ; i < n ; ++i)printf(" %d %d", ax[i], ay[i]);
        puts("");
    }    
    return 0;
}
