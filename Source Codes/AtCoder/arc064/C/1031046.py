#!/usr/bin/env python3

import math
import itertools


INVALID = -1
INF = 10 ** 12


def dijkstra_dense(num_vs, adj_matrix, source, dest):
    dist = [INF for _ in range(num_vs)]
    visited = [False for _ in range(num_vs)]
    dist[source] = 0
    while True:
        u = min((j for j in range(num_vs) if not visited[j]),
                key=lambda i: dist[i], default=INVALID)
        if u == INVALID or dist[u] == INF:
            break
        visited[u] = True
        for v in range(num_vs):
            w = adj_matrix[u][v]
            if u != v and w < INF:
                new_len = dist[u] + w
                if new_len < dist[v]:
                    dist[v] = new_len
    return dist[dest]


def main():
    # ?????0??????N + 1???
    x0, y0, xf, yf = (int(x) for x in input().split())
    n = int(input())
    xs = [None for _ in range(n + 2)]
    ys = [None for _ in range(n + 2)]
    rs = [None for _ in range(n + 2)]
    xs[0], ys[0], rs[0] = x0, y0, 0
    xs[n + 1], ys[n + 1], rs[n + 1] = xf, yf, 0
    for i in range(1, n + 1):
        xs[i], ys[i], rs[i] = (int(z) for z in input().split())
    adj_matrix = [[INF for _ in range(n + 2)] for _ in range(n + 2)]
    for i, j in itertools.product(range(n + 2), repeat=2):
        adj_matrix[i][j] = max(0, math.hypot(xs[i] - xs[j],
                                             ys[i] - ys[j]) - (rs[i] + rs[j]))
    res = dijkstra_dense(n + 2, adj_matrix, 0, n + 1)
    print("{:.12f}".format(res))


if __name__ == '__main__':
    main()