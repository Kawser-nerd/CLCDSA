#include <stdio.h>
#define max(a, b) (a>b ? a:b)

int main(int argc, char const *argv[]) {
    // ??
    int N;
    // ??
    scanf("%d", &N);
    // ?? ? 1???????????
    int dist, maxdist = 0;
    int v;
    for (int i = 2; i <= N; i++) {
        printf("? 1 %d\n", i);
        fflush(stdout);
        scanf("%d", &dist);
        if (maxdist < dist) {
            maxdist = dist;
            v = i;
        }
    }
    // ???????
    int ans = maxdist;
    for (int i = 1; i <= N; i++) {
        if (i == v) {
            continue;
        }
        printf("? %d %d\n", v, i);
        fflush(stdout);
        scanf("%d", &dist);
        if (ans < dist) {
            ans = dist;
        }
    }
    // ??
    printf("! %d\n",ans);
    fflush(stdout);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:15:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &dist);
         ^
./Main.c:29:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &dist);
         ^