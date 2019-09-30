#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void cango(int m, int p, int*a, int*b, int*flags){
    flags[p] = 1;
    rep(m, i) {
        if (a[i] == p && !flags[b[i]]) cango(m, b[i], a, b, flags);
        else if (b[i] == p && !flags[a[i]]) cango(m, a[i], a, b, flags);
    }
}

void solve(void){
    int n, m;
    scanf("%d %d\n", &n, &m);
    int a[m], b[m];
    rep(m, i) {
        scanf("%d %d\n", &a[i], &b[i]);
        a[i]--; b[i]--;
    }

    int ans = 0;
    rep(m, j){
        int al[m-1], bl[m-1];       //?????
        int c = 0;                  //index??
        for(int k = 0; k < m-1; k++) {
            if (k == j) c = 1;
            al[k] = a[k+c];
            bl[k] = b[k+c];
        }
        int flag = 0;
        int flags[n];
        rep(n, i) flags[i] = 0;

        cango(m-1, 0, al, bl, flags);
        rep(n, i) if (!flags[i]) flag = 1;
        if (!flag) ans++;
    }
  printf("%d\n", m-ans);
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d\n", &n, &m);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d\n", &a[i], &b[i]);
         ^