#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int testcase() {
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);

    int noship[C + 1];
    int last[C + 1];

    for(int i = 0; i < W; ++i)
        noship[i] = 0, last[i] = -10000000;

    last[W] = W;

    for(int i = W; i <= C; ++i) {
        int res = 1000000;

        for(int j = 0; j < i; ++j) {
            int cur = 1 + noship[j] + noship[i - j - 1];
            if(cur < res)
                res = cur;
        }

        noship[i] = res;
    }

    for(int i = W + 1; i <= C; ++i) {
        int res = 1000000;

        for(int j = 0; j < i; ++j) {
            int cur = 1 + max(noship[j] + last[i - j - 1], last[j] + noship[i - j - 1]);
            if(cur < res && cur >= 0)
                res = cur;
        }

        last[i] = res;
    }

    return (R - 1) * noship[C] + last[C];
}

int main() {
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; ++i) {
        printf("Case #%d: %d\n", i, testcase());
    }
}
