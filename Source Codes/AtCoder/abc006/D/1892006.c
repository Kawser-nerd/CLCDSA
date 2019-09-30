#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define rep(n, i) for(int i = 0; i < n; i++)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define Max 40000

int binarysearch_index(int a, int* xs, int len){
    if (len <= 1) if (xs[0] > a) xs[0] = a; else xs[1] = a;
    else {
        int mid = len / 2 + 1;
        int p = xs[mid-1];
        if (p > a) binarysearch_index(a, &xs[0], mid - 1);
        else binarysearch_index(a, &xs[mid], len - mid);
    }
}

int dp_n(int n, int xs[]){
    int length = 1, ls[n];
    ls[0] = Max;
    rep(n, i) {
        if (ls[length-1] > xs[i]) binarysearch_index(xs[i], ls, length);
        else {
            ls[length] = xs[i];
            length += 1;
        }
    }
    return length;
}

void solve(void){
    int n;
    scanf("%d\n", &n);
    int xs[n];
    rep(n, i) scanf("%d\n", &xs[i]);
    dp_n(n, xs);
  printf("%d\n", n - dp_n(n, xs));
}

int main(void){
  solve();
  return 0;
} ./Main.c: In function ‘solve’:
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:37:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     rep(n, i) scanf("%d\n", &xs[i]);
               ^