#!/usr/bin/env python3

import math

def gcd(a, b):
    if a < b:
        a, b = b, a
    q, r = a, b
    while r:
        q, r = r, q % r

    return q


def lcm(a, b):
    return a * b // gcd(a, b)

MAX_N = 102
INF = 10 ** 12
SRC = 0
DST = MAX_N - 1
g = [[0] * MAX_N for _ in range(MAX_N)]
level = []
visited = []
n = 0


def bfs(s):
    global level

    level = [-1] * MAX_N
    level[s] = 0
    que = [s]
    while 0 < len(que):
        v = que.pop(0)
        for w in range(MAX_N):
            if 0 < g[v][w] and level[w] < 0:
                level[w] = level[v] + 1
                que.append(w)


def dfs(v, t, f):
    global g, visited

    if v == t:
        return f
    for w in range(visited[v], MAX_N):
        visited[v] = w
        if 0 < g[v][w] and level[v] < level[w]:
            d = dfs(w, t, min(f, g[v][w]))
            if 0 < d:
                g[v][w] -= d
                g[w][v] += d
                return d

    return 0


def max_flow():
    global visited

    flow = 0
    while True:
        bfs(SRC)
        if level[DST] < 0:
            return flow
        visited = [0] * MAX_N
        f = dfs(SRC, DST, INF)
        while 0 < f:
            flow += f
            f = dfs(SRC, DST, INF)


def solve(n, a):
    global g

    sum_positive = sum([v for v in a if 0 < v])

    for i in range(1, n + 1):
        if 0 < a[i]:
            g[SRC][i] = a[i]
        elif a[i] < 0:
            g[i][DST] = -a[i]
            for j in range(i * 2, n + 1, i):
                if 0 < a[j]:
                    g[j][i] = INF

    return sum_positive - max_flow()


def main():
    global n

    n = int(input())
    a = list(map(int, input().split()))
    a = [0] + a

    print(solve(n, a))


if __name__ == '__main__':
    main()