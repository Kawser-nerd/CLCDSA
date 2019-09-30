#!/usr/bin/env python3
from itertools import product
K, N = map(int, input().split())
vs = [None] * N
ws = [None] * N


def solve(num):
    ans = [None] * K
    for v, w in zip(vs, ws):
        cur = 0
        for n in v:
            if ans[n] is not None and ans[n] != w[cur:cur + num[n]]:
                return False
            ans[n] = w[cur:cur + num[n]]
            cur += num[n]

        if cur != len(w):
            return False

    print(*ans, sep='\n')
    return True


def enum():
    for arr in product(range(1, 4), repeat=K):
        if solve(arr):
            return


for i in range(N):
    vs[i], ws[i] = input().split()
    vs[i] = [int(x) - 1 for x in vs[i]]

enum()