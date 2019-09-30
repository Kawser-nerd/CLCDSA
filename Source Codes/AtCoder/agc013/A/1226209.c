#include <stdio.h>
#define MAXN 1<<17
int a[MAXN], n;
int solve(void) {
    int res = 1;
    int mov = 0;
    for(int i = 0; i < n - 2; i++) {
        if(a[i] == a[i + 1] && a[i + 1] == a[i + 2]) continue;
        else if(a[i] >= a[i + 1] && a[i + 1] >= a[i + 2] && mov != 2) mov = 1;
        else if(a[i] <= a[i + 1] && a[i + 1] <= a[i + 2] && mov != 1) mov = 2;
        else {
            mov = 0;
            res++;
            i++;
        }
    }
    return res;
} 
int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", solve());
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^