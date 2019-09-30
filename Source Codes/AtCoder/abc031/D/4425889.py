#!/usr/bin/env python3
K, N = map(int, input().split())
vs = [None] * N
ws = [None] * N
num = [0] * K


def solve():
    ans = [None] * K
    for v, w in zip(vs, ws):
        cur = 0
        for n in map(lambda x: int(x) - 1, v):
            if ans[n] is not None and ans[n] != w[cur:cur + num[n]]:
                return None
            ans[n] = w[cur:cur + num[n]]
            cur += num[n]
        if cur != len(w):
            return None
    return ans


def dfs(k):
    if k == K:
        return solve()
    for i in range(3):
        num[k] = i + 1
        ans = dfs(k + 1)
        if ans is not None:
            return ans


for i in range(N):
    vs[i], ws[i] = input().split()

print(*dfs(0), sep='\n')