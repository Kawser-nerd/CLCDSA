#!/usr/bin/env python3
n, x = map(int, input().split())
x -= 1
h = list(map(int, input().split()))
tree = [[] for _ in range(n)]
for i in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)
ans = 0


def dfs(prev, s):
    global ans
    ors = False
    for t in tree[s]:
        if t == prev:
            continue
        res = dfs(s, t)
        ans += res * 2
        ors |= res
    return ors | h[s]


dfs(-1, x)
print(ans)