#include <stdio.h>

int dat[200001] = {};
int main() {
    long n, q;
    scanf("%ld %ld", &n, &q);
    for (long i=0; i<q; i++) {
        long l, r;
        scanf(" %ld %ld", &l, &r);
        dat[l]++;
        dat[r+1]++;
    }
    for (long i=1; i<=n; i++) {
        dat[i] = dat[i-1] + dat[i];
        printf("%d", dat[i]%2);
    }
    puts("");
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld", &n, &q);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf(" %ld %ld", &l, &r);
         ^