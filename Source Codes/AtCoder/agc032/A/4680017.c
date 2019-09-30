#include <stdio.h>
#include <stdlib.h>

int main() {
    long i, n, done = 0, place, temp;
    long b[101], sub[101];

    scanf("%ld", &n);

    b[0] = 0;
    sub[0] = 0;
    for (i=1; i<=n; i++) {
        scanf("%ld", &b[i]);
        sub[i] = 0;
    }

    while (done < n) {
        place = n - done;
        temp = place;
        for (i = n; i >= 1; i--) {
            if (b[i] == 0) {
                continue;
            }
            if (place == b[i]) {
                sub[n-done] = place;
                b[i] = 0;
                done++;
                break;
            }
            place--;
        }
        if (temp == n - done) {
            printf("-1\n");
            return 0;
        }
    }

    for (i = 1; i <= n; i++) {
        printf("%ld\n", sub[i]);
    }

    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld", &n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%ld", &b[i]);
         ^