/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct _pair {
    int a, b;
} pair;

int cmp(const void *a, const void *b) {
    int res = (*(pair*)a).a - (*(pair*)b).a;
    if (res == 0) res = (*(pair*)a).b - (*(pair*)b).b;
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    pair ab[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &ab[i].a, &ab[i].b);
    }
    int res = 0;
    qsort(ab, n, sizeof(pair), cmp);
    for (int i = 0; i < n; i++) {
        int l = 0, r = n;
        while (r - l > 0) {
            int mid = (r + l) / 2;
            if (ab[i].b < ab[mid].a) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        //printf("%d %d: %d %d\n", ab[i].ah, ab[i].b, l, r);
        res = res < l - i ? l - i : res;
    }
    printf("%d\n", res);
}
*/
#include <stdio.h>

int main() {
    int s[1000001] = {0};
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        s[a]++;
        s[b+1]--;
    }
    int res = s[0];
    for (int i = 1; i <= 1000000; i++) {
        s[i] += s[i-1];
        res = res < s[i] ? s[i] : res;
    }
    printf("%d\n", res);
} ./Main.c: In function ‘main’:
./Main.c:45:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:47:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^