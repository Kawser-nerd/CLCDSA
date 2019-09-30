#include <stdio.h>
#include <stdlib.h>
#define min(a, b) (a<b ? a:b)

// ????
long lPow (long n, long m) {
    if (m == 0) {
        return 1;
    } else if (m == 1) {
        return n;
    } else if (m%2 == 0) {
        return lPow(n, m/2)*lPow(n, m/2);
    } else {
        return n*lPow(n, m-1);
    }
}
// ??????
void InitDist (int N, long **dist) {
    long INF = lPow(10, 9);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    //printf("call InitDist\n");
}
// ??????????
void WFmethod (int N, long **dist) {
    for (size_t k = 1; k < N; k++) {
        for (size_t i = 1; i < N; i++) {
            for (size_t j = 1; j < N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
}
// ??????????
void calcShortestRoot (int N, int M) {
    // ????
    long **dist;
    // ?????
    dist = (long **)malloc(sizeof(long *)*N);
    for (size_t i = 0; i < N; i++) {
        dist[i] = (long *)malloc(sizeof(long)*N);
    }
    int node1, node2;
    long distance;
    InitDist(N, dist);
    for (size_t i = 0; i < M; i++) {
        scanf("%d %d %ld ", &node1, &node2, &distance);
        node1--; node2--;
        dist[node1][node2] = distance;
        dist[node2][node1] = distance;
    }
    // ??????????
    WFmethod(N, dist);
    // ?????????
    long INF = lPow(10,9);
    long ans = INF;
    for (size_t i = 1; i < N; i++) {
        for (size_t j = i+1; j < N; j++) {
                ans = min(ans, dist[0][i] + dist[j][0] + dist[i][j]);
        }
    }
    // ??
    if (ans < INF) {
        printf("%ld\n", ans );
    } else {
        printf("-1\n");
    }
    // ?????
    free(dist);
}

// ???
int main(int argc, char const *argv[]) {
    // ??
    int N, M;
    // ??
    scanf("%d %d", &N, &M);
    // ??
    calcShortestRoot(N, M);
    return 0;
} ./Main.c: In function ‘calcShortestRoot’:
./Main.c:54:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %ld ", &node1, &node2, &distance);
         ^
./Main.c: In function ‘main’:
./Main.c:84:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &N, &M);
     ^