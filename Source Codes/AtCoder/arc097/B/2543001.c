/*
 * Fast UNION(??????UNION) + ????
 * (??????????????(?????)8?)
 */
#include <stdio.h>

#define N 100000

/* ??????????????: */
/* ???: ???????????????????*(-1) */
/* ???: ?????????? */
int S[N+1];

/* ??????????? */
int P[N+1];

void makeset(int size) {
    int i;
    /* ???????1??????????????? */
    for (i = 1; i <= size; i++) {
        S[i] = -1; /* ????????1 */
    }
}

int find(int x) {
    if (S[x] < 0) {
        return x;
    }


    return S[x] = find(S[x]);
}

void merge(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);

    if (root1 == root2) {
        return;
    }

    /* ??????????????*/
    /* ????-1???????????????????? */
    if (S[root2] < S[root1]) {
        /** root1?root2????? */
        S[root2] += S[root1];
        S[root1] = root2;
    } else {
        /** root2?root1????? */
        S[root1] += S[root2];
        S[root2] = root1;
    }
}

int main()
{
    int i;
    int n, m;
    int x, y;
    int r;

    scanf("%d %d", &n, &m);

    makeset(n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &P[i]);
    }

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        merge(x, y);
    }

    r = 0;
    for (i = 1; i <= n; i++) {
        if (find(i) == find(P[i])) {
            r++;
        }
    }

    printf("%d\n", r);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:62:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:67:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &P[i]);
         ^
./Main.c:71:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &x, &y);
         ^