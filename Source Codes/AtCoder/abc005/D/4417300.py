# coding: utf-8

# ?????????? 1<= n <= 50
n = int(input())
# ????????? 1 <= Dij <= 100 ???????????
d = [list(map(int, input().rstrip().split())) for _ in range(n)]
# ????? 1 <= q <= n^2 (2500!)
q = int(input())
# ??????? 1 <= p[k] <= n^2
p = [int(input()) for _ in range(q)]

# ??(i, j)??(x, y): i <= x <= n, j <= y <= n ?????????
# ??????????
darea = lambda i, j, ii, jj: \
    r[i][j] - r[ii + 1][j] - r[i][jj + 1] + r[ii + 1][jj + 1]

# r[i][j]: ??(i, j)????(n, n)?????????????
r = [[0 for _ in range(n + 1)] for __ in range(n + 1)]
for i in range(n - 1, -1, -1):
    for j in range(n - 1, -1, -1):
        r[i][j] = d[i][j] + \
            r[i + 1][j] + r[i][j + 1] - r[i + 1][j + 1]

dmax = [0 for _ in range(n ** 2 + 1)]
# ???????????
for i in range(n):
    for j in range(n):
        for ii in range(i, n):
            for jj in range(j, n):
                num = (ii - i + 1) * (jj - j + 1)
                d = darea(i, j, ii, jj)
                if dmax[num] < d:
                    dmax[num] = d
# print(dmax)
m = 0
for i in range(n ** 2 + 1):
    if m > dmax[i]:
        dmax[i] = m
    else:
        m = dmax[i]
for pk in p:
    print(dmax[pk])