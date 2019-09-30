#include <stdio.h>
int n, k, s[100020]={}, a=0, b=0, ans=0;
long d=1;
int main() {
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
        scanf(" %d", &s[i]);
        if (s[i] == 0) {
            printf("%d\n", n);
            return 0;
        }
    }
    while(a < n) {
        while (d*s[b] <= k && b < n)
            d *= s[b++];
        if (b-a > ans)
            ans = b-a;
        d /= s[a++];
        if (d == 0)
            d=1;
    }
    printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf(" %d", &s[i]);
         ^