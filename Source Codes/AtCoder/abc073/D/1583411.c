#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int n, m, r, rs[8], a, b, c, adj[200][200], dist[200][200];
static int prev[200], q[200];
int q_is_empty(void) {
    int i;
    for (i = 0; i < n; ++i)
        if (q[i])
            return 0;
    return 1;
}
int q_pop_min(int s) {
    int i, min_dist = INT_MAX, min_dist_v = -1;
    for (i = 0; i < n; ++i)
        if (q[i])
            if (dist[s][i] < min_dist) {
                min_dist = dist[s][i];
                min_dist_v = i;
            }
    q[min_dist_v] = 0;
    return min_dist_v;
}
void dijkstra(int s) {  // start
    int i, v, u;
    for (i = 0; i < n; ++i) {
        if (i == s)
            dist[s][i] = 0;
        else
            dist[s][i] = INT_MAX;
    }
    for (i = 0; i < n; ++i)
        prev[i] = -1;
    for (i = 0; i < n; ++i)
        q[i] = 1;
    while (!q_is_empty()) {
        u = q_pop_min(s);
        for (i = 0; i < n; ++i) {
            if (adj[u][i]) {
                v = i;
                if (dist[s][v] > dist[s][u] + adj[u][v]) {
                    dist[s][v] = dist[s][u] + adj[u][v];
                    prev[v] = u;
                }
            }
        }
    }
}
void print_rs(int *rs, int r) {
    int i;
    for (i = 0; i < r; ++i) {
        printf("%d, ", rs[i]);
    }
    putchar('\n');
}
int rec(int *rs, int r, int parent, int d, int depth) {
    int i, *rs2, num_child = 0, min = INT_MAX, min_children;
//    print_rs(rs, r);
    for (i = 0; i < r; ++i) {
        if (rs[i] != -1) {
            ++num_child;
            rs2 = malloc(sizeof(int) * r);
            memcpy(rs2, rs, sizeof(int) * r);
            rs2[i] = -1;
            min_children = rec(rs2, r, rs[i], d + dist[parent][rs[i]], depth + 1);
            if (min_children < min)
                min = min_children;
            free(rs2);
        }
    }
    if (!num_child) {
        return d;
    } else
        return min;
}
void print_adj(void) {
    int i, j;
    puts("adjacency matrix:");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d, ", adj[i][j]);
        }
        putchar('\n');
    }
}
void print_dist(void) {
    int i, j;
    puts("distance:");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            printf("%d, ", dist[i][j]);
        }
        putchar('\n');
    }
}
int main(void) {
    int i, *rs2, min = INT_MAX, min_children;
    scanf("%d%d%d", &n, &m, &r);
    for (i = 0; i < r; ++i) {
        scanf("%d", rs + i);
        --rs[i];
    }
    for (i = 0; i < m; ++i) {
        scanf("%d%d%d", &a, &b, &c);
        --a;
        --b;
        adj[a][b] = c;
        adj[b][a] = c;
    }
    for (i = 0; i < n; ++i) {
        dijkstra(i);
    }
//    print_adj();
//    print_dist();
    for (i = 0; i < r; ++i) {
        rs2 = malloc(sizeof(int) * r);
        memcpy(rs2, rs, sizeof(int) * r);
        rs2[i] = -1;
        min_children = rec(rs2, r, rs[i], 0, 100);
        if (min_children < min)
            min = min_children; 
        free(rs2);
    }
    printf("%d\n", min);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:99:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &n, &m, &r);
     ^
./Main.c:101:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", rs + i);
         ^
./Main.c:105:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d%d", &a, &b, &c);
         ^