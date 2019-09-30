#include <stdio.h>
#include <stdlib.h>

#define MAX 100007

struct pair {
        long a;
        int b;
};

int compare(const void *x, const void *y) {
        long x_a = ((struct pair *) x)->a;
        long y_a = ((struct pair *) y)->a;
        return x_a - y_a;
}

int main() {
        int N, M;
        scanf("%d %d", &N, &M);

        struct pair AB[MAX];
        for (int i = 0; i < N; i++)
                scanf("%ld %d", &AB[i].a, &AB[i].b);
        qsort(AB, N, sizeof(struct pair), compare);

        struct pair ab = {0, 0};
        for (int i = 0; i < N; i++) {
                if (ab.b + AB[i].b <= M) {
                        ab.a += AB[i].a * AB[i].b;
                        ab.b += AB[i].b;
                } else {
                        ab.a += AB[i].a * (M - ab.b);
                        break;
                }
        }
        printf("%ld\n", ab.a);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &N, &M);
         ^
./Main.c:23:17: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
                 scanf("%ld %d", &AB[i].a, &AB[i].b);
                 ^