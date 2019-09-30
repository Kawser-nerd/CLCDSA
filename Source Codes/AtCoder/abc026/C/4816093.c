#include <stdio.h>
#include <stdlib.h>
#define Nmax 21
#define max(a, b) (a>b ? a:b)
#define min(a, b) (a<b ? a:b)
// ???
typedef struct list_t {
    int sub;    // ??
    int size;   // ????????????
    struct list_t *head;    // ??????
    struct list_t *previous;    // ??????
} list_t;
// ???????
void  InitList (int N, list_t list[]) {
    for (size_t i = 0; i < N; i++) {
        list[i].size = 0;
        list[i].head = &list[i];
        list[i].previous = NULL;
    }
}
// ??????
void addList (int Sub, int boss, list_t a[]) {
    list_t *new_l;
    new_l = (list_t *)malloc(sizeof(list_t));   // ????????
    new_l -> size = ((a[boss].head) -> size) + 1;
    new_l -> sub = Sub;
    new_l -> previous = a[boss].head;
    a[boss].head = new_l;
}
// ??????????
void  makeList (list_t *Sub, int N, int B[]) {
    InitList(N, Sub);
    for (int i = 1; i < N; i++) {
        addList(i, B[i], Sub);
    }
}
// ?????
void calcSalary (int N, int B[]) {
    list_t *Sub;
    Sub = (list_t *)malloc(sizeof(list_t)*N);
    // ????
    makeList(Sub, N, B);
    // ????????
    int P[N], minP[N], maxP[N];
    list_t *buf;
    for (int i = N-1; i >= 0; i--) {
        buf = Sub[i].head;
        if (buf -> size == 0) {
            P[i] = 1;
            continue;
        }
        maxP[i] = 0; minP[i] = (int)1e9;
        while ( (buf -> previous) != '\0' ) {
            int j = buf -> sub;
            maxP[i] = max(maxP[i], P[j]);
            minP[i] = min(minP[i], P[j]);
            buf = (buf -> previous);
        }
        P[i] = maxP[i]+minP[i]+1;
    }
    // ??
    printf("%d\n", P[0]);
    // ?????
    free(Sub);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    int N;
    // ??
    int B[Nmax] = {0};
    scanf("%d", &N);
    for (size_t i = 1; i < N; i++) {
        scanf("%d", &B[i]);
        B[i] --;
    }
    // ??
    calcSalary(N, B);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:73:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:75:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &B[i]);
         ^