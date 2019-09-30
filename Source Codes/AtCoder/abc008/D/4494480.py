# coding: utf-8
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)

@lru_cache(maxsize = None)
def dp(l, u, r, d):
    g = 0
    for x, y in ml:
        if l <= x <= r and u <= y <= d:
            g_ = r - l + 1 + d - u + \
                dp(l, u, x - 1, y - 1) + \
                dp(x + 1, u, r, y - 1) + \
                dp(l, y + 1, x - 1, d) + \
                dp(x + 1, y + 1, r, d)
            if g_ > g:
                g = g_
    return(g)

w, h = map(int, input().rstrip().split())
n = int(input())
ml = [list(map(int, input().rstrip().split())) for _ in range(n)]

print(dp(1, 1, w, h))