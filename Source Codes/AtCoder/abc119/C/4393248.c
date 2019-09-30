#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

int N, A, B, C, l[10];

int min(int len, ...) {
    int i, _min, num;
    va_list ap;
    va_start(ap, len);

    _min = va_arg(ap, int);
    for (i = 1; i < len; i++) {
        num = va_arg(ap, int);
        if (num < _min)
            _min = num;
    }
    va_end(ap);
    return _min;
}

int dfs(int cur, int a, int b, int c) {
    int ret0, ret1, ret2, ret3;
    if (cur == N+1) {
        if (min(3, a, b, c) > 0) return abs(a - A) + abs(b - B) + abs(c - C) - 30;
        else return INF;
    }
    ret0 = dfs(cur + 1, a, b, c);
    ret1 = dfs(cur + 1, a + l[cur], b, c) + 10;
    ret2 = dfs(cur + 1, a, b + l[cur], c) + 10;
    ret3 = dfs(cur + 1, a, b, c + l[cur]) + 10;
    return min( 4, ret0, ret1, ret2, ret3 );
}

int main(void) {
    int i;
    scanf("%d%d%d%d", &N, &A, &B, &C);
    for (i=1;i<=N;i++) scanf("%d", &l[i]);

    printf("%d\n", dfs(1,0,0,0));

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d", &N, &A, &B, &C);
     ^
./Main.c:40:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     for (i=1;i<=N;i++) scanf("%d", &l[i]);
                        ^