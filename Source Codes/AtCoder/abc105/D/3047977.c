#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long diff = *(long long *)a - *(long long *)b;
    return diff < 0 ? -1 : (diff > 0 ? 1 : 0);
}

int main() {
    
    int i, j, N, M;
    long long a[100001], v = 0, r;
    
    scanf("%d %d", &N, &M);
    
    a[0] = 0;
    for (i = 1; i <= N; i++) {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
        a[i] %= M;
    }
    
    qsort(a + 1, N, sizeof(long long), compare);
    
    for (i = 1, j = 0; i <= N; i++) {
        if (a[i] != a[j]) {
            r = i - j;
            v += r * (r - 1) / 2;
            j = i;
        }
    }
    r = i - j;
    v += r * (r - 1) / 2;
    
    printf("%lld\n", v);
    
    return 0;
    
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld", &a[i]);
         ^