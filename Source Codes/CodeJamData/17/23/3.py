import numpy as np
tests = int(input())
INF = 1e17


def solve():
    n, q = map(int, input().split())
    horses = [list(map(int, input().split())) for i in range(n)]

    g = np.array([list(map(int, input().split())) for i in range(n)])
    g[g == -1] = INF

    for k in range(n):
        for i in range(n):
            for j in range(n):
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])

    t = np.zeros((n, n)) + INF
    for i in range(n):
        t[i] = g[i] / horses[i][1]
        t[i][g[i] > horses[i][0]] = INF

    for k in range(n):
        for i in range(n):
            for j in range(n):
                t[i][j] = min(t[i][j], t[i][k] + t[k][j])

    for query in [list(map(int, input().split())) for i in range(q)]:
        print(t[query[0] - 1][query[1] - 1], end=" ")
    print()


for ti in range(1, tests + 1):
    print("Case #{}: ".format(ti), end="")
    solve()
