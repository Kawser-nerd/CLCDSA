#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int st;
    int ed;
} TIMES;

int round_st(int d) {
    int n;

    n = d % 10;
    if (n == 0 || n == 5) {
        return d;
    }

    if (n >= 5) {
        return d - (n - 5);
    } else {
        return d - n;
    }
}

int round_ed(int d) {
    int n, m;

    n = d % 10;
    if (n == 0 || n == 5) {
        return d;
    }

    if (n > 5) {
        m = d % 100;
        if (m + (10 - n) >= 60) {
            return d + 100 - m;
        } else {
            return d + (10 - n);
        }
    } else {
        return d + (5 - n);
    }
}

int cmp(const void *a, const void *b) {
    TIMES t1 = *(TIMES *)a;
    TIMES t2 = *(TIMES *)b;

    if (t1.st < t2.st) {
        return -1;
    } else if (t1.st > t2.st) {
        return 1;
    } else {
        if (t1.ed < t2.ed) {
            return -1;
        } else if (t1.ed > t2.ed) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    int n, st, ed;
    TIMES *times, tmp;

    scanf("%d", &n);
    times = (TIMES *)malloc(sizeof(TIMES) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d-%d", &st, &ed);
        times[i].st = round_st(st);
        times[i].ed = round_ed(ed);
    }

    qsort(times, n, sizeof(TIMES), cmp);

    tmp.st = times[0].st;
    tmp.ed = times[0].ed;
    for (int i = 1; i < n; i++) {
        if (tmp.ed >= times[i].st) {
            if (tmp.ed < times[i].ed) {
                tmp.ed = times[i].ed;
            }
        } else {
            printf("%04d-%04d\n", tmp.st, tmp.ed);
            tmp.st = times[i].st;
            tmp.ed = times[i].ed;
        }
    }

    printf("%04d-%04d\n", tmp.st, tmp.ed);

    if (times != NULL) {
        free(times);
        times = NULL;
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:71:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d-%d", &st, &ed);
         ^