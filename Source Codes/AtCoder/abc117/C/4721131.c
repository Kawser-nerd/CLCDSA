#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    int p = *(int*)a, q = *(int*)b;
    if( p > q) { return 1; }
    else if( p == q) { return 0; }
    else { return -1; }
}

int cmp1(const void *a, const void *b){
    int p = *(int*)a, q = *(int*)b;
    if( p > q) { return -1; }
    else if( p == q) { return 0; }
    else { return 1; }
}

void solve(int *a, int n, int m) {
    if(n > m) { printf("0\n"); return ;}
    qsort(a, m, sizeof(int), cmp);
    int i, ans;
    int *b = (int*)malloc(m*sizeof(int));
    for(i = 1; i < m; ++i) {
        b[i-1] = a[i] - a[i-1]; 
    }
    qsort(b, m-1, sizeof(int), cmp1);
    ans = a[m-1] - a[0];
    for(i = 0; i < n-1; ++i) {
        ans -= b[i];
    }
    printf("%d\n", ans);
    free(b); free(a);
}

int main(void)
{
    int n, m, i;
    scanf("%d %d", &n, &m);
    int *a = (int*)malloc((m+1)*sizeof(int));
    for(i = 0; i < m; ++i) { scanf("%d", &a[i]); }
    solve(a, n, m);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:40:30: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for(i = 0; i < m; ++i) { scanf("%d", &a[i]); }
                              ^