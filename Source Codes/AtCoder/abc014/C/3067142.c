#include <stdio.h>
#include <stdlib.h>

typedef struct elem {
    int index;
    int diff;
} elem_t;

static int compar(const void *a, const void *b) {
    const elem_t *a_ = a, *b_ = b;
    return a_->index - b_->index;
}

int main() {
    int n;
    scanf("%d", &n);
    elem_t *ary = malloc(sizeof(elem_t) * (2 * n));
    for (int i = 0; i < 2 * n; i += 2) {
        int a, b;
        scanf("%d%d", &a, &b);
        ary[i].index = a;
        ary[i].diff = 1;
        ary[i + 1].index = b + 1;
        ary[i + 1].diff = -1;
    }

    qsort(ary, 2 * n, sizeof(elem_t), compar);

    int ans = 0, cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        for (; i + 1 < 2 * n && ary[i].index == ary[i + 1].index; i++) {
            cur += ary[i].diff;
        }
        cur += ary[i].diff;
        ans = ans > cur ? ans : cur;
    }
    free(ary);
    printf("%d\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:20:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^