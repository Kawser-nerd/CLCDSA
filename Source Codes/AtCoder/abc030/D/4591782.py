#!/usr/bin/env python3
N, a = map(int, input().split())
k = int(input())
b = list(map(lambda x: int(x) - 1, input().split()))

rb = [[] for _ in range(N)]
for i, x in enumerate(b):
    rb[x].append(i)

cmp = [None] * N
g = []
used = []
li = []


def dfs(s):
    global used
    used[s] = True
    t = b[s]
    if not used[t]:
        dfs(t)
    li.append(s)


def rdfs(s, c):
    global used
    used[s] = True
    cmp[s] = c
    g[-1].append(s)
    for t in rb[s]:
        if not used[t]:
            rdfs(t, c)


def scc():
    global used
    used = [False] * N
    for i in range(N):
        if not used[i]:
            dfs(i)
    used = [False] * N
    c = 0
    for i in range(len(li))[::-1]:
        if not used[li[i]]:
            g.append([])
            rdfs(li[i], c)
            g[-1] = g[-1][::-1]
            c += 1
    return c


def solve(s, k):
    global used
    if used[s] or k == 0:
        p = cmp[s]
        return g[p][(k + g[p].index(s)) % len(g[p])]
    used[s] = True
    return solve(b[s], k - 1)


scc()
used = [False] * N
print(solve(a - 1, k) + 1)