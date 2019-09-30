#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int find_max(int a[], int n){
    int max_index = 0;
    rep(n-1, i) if (a[max_index] < a[i+1]) max_index = i+1;
    return a[max_index];
}

int dp_n2(int n, int xs[]){
    int ls[n+1];
    ls[0] = 0;
    for (int i = 1; i < n+1; i++) {
        int k = 0;
        rep (i, j) {
            if ((ls[j] > ls[k]) && (xs[i] > xs[j])) k = j;
        }
        ls[i] = ls[k] + 1;
    }
    return find_max(ls, n+1);
}

void solve(void){
    int n;
    scanf("%d\n", &n);
    //xs begins with -1
    int xs[n+1];
    xs[0] = -1;
    rep(n, i) scanf("%d\n", &xs[i+1]);

  printf("%d\n", n - dp_n2(n, xs));
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:34:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(n, i) scanf("%d\n", &xs[i+1]);
               ^