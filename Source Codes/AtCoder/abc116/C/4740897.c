#include <stdio.h>
#include <stdlib.h>

/*
void parray(int *a, int n) {
    int i;
    for(i = 0; i < n; ++i) { printf("%d ", a[i]); }
    printf("\n"); 
}
*/

int *sep(int *a, int n, int *cnt) { // 0????????????????
    int *p = (int*)malloc((n+3) * sizeof(int));
    int i, c = 0;
    p[c] = -1; ++c;
    for(i = 0; i < n; ++i) {
        if(a[i] == 0) { p[c] = i; ++c; }
    }
    p[c] = n; ++c;
    *cnt = c;
    return p;
}

int min(int *a, int i, int j) {
    int k, min = a[i];
    for(k = i; k <= j; ++k) {
        if( a[k] > 0 && a[k] < min) { min = a[k]; }
    }
    return min;
}

int sub(int *a, int i, int j) {
    int k, x = min(a, i, j);
    for(k = i; k <= j; ++k) { a[k] -= x; }
    return x;
}

void solve(int *a, int n) {
    int i, cnt, ans, *chk, check;
    ans = 0;
    do {
        chk = sep(a, n, &cnt);
        check = 0;
        //printf("chk: "); parray(chk, cnt);
        for(i = 0; i < cnt - 1; ++i) {
            check += sub(a, chk[i] + 1, chk[i+1] - 1);
        }
        ans += check;
        //printf("a: "); parray(a, n);
        free(chk);
    } while(check > 0);
    printf("%d\n", ans);
}

int main(void)
{
    int n, i;
    scanf("%d", &n);
    int *h = (int*)malloc((n+2)*sizeof(int));
    for(i = 0; i < n; ++i) { scanf("%d", &h[i]); }
    solve(h, n);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:58:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:60:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 0; i < n; ++i) { scanf("%d", &h[i]); }
                              ^