#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int ans;

int main() {
    int n, t;
    scanf("%d%d", &n, &t);

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    long long int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1] + t) {
            ans += t;
        } else {
            ans += (a[i] - a[i - 1]);
        }
    }

    printf("%d\n", ans + t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
     printf("%d\n", ans + t);
            ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &t);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &a[i]);
         ^