#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>

#define N 32
#define J 500

#define int long long int

typedef struct {
    char *s;
    int divs[9]; // unused
} ansstr;

char s[N];
char divs[N];
ansstr answers[J];
int answers_ptr = 0;

int conv(char *ss, int base) {
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        ret *= base;
        ret += ss[i] - '0';
    }
    return ret;
}

char gen(int i) {
    if (i >= N / 2 - 1) {
        memcpy(s + N / 2, s, N / 2);
        ansstr ans;
        ans.s = malloc(N + 1);
        memcpy(ans.s, s, N);
        ans.s[N] = 0;
        answers[answers_ptr++] = ans;
        if (answers_ptr >= J) {
            return 1;
        }
        return 0;
    } else {
        s[i] = '0';
        if (gen(i + 1)) {
            return 1;
        }
        s[i] = '1';
        return gen(i + 1);
    }
}

int32_t main(void) {
    s[0] = s[N / 2 - 1] = s[N / 2] = s[N - 1] = '1';
    printf("Case #1:\n");
    for (int i = 0; i < N; ++i) {
        divs[i] = '0';
    }
    divs[N - 1] = divs[N / 2 - 1] = '1';
    gen(1);
    for (int i = 0; i < answers_ptr; ++i) {
        printf("%s ", answers[i].s);
        free(answers[i].s);
        for (int j = 2; j <= 10; ++j) {
            printf("%lld ", conv(divs, j));
        }
        printf("\n");
    }

    return 0;
}
