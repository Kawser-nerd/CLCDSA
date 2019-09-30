# coding: utf-8
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)

mInF = lambda x, y, w, h, m: \
    x <= m[0] <= x + w - 1 and y <= m[1] <= y + h - 1

@lru_cache(maxsize = None)
def dfs(ox, oy, w, h):
    g = [0]
    for i, m in enumerate(ml):
        g_ = w + h - 1
        if mInF(ox, oy, w, h, m):
            mx, my = m
            lw = mx - ox
            rw = ox + w - 1 - mx
            uh = my - oy
            dh = oy + h - 1 - my
            g_ += dfs(ox, oy, lw, uh) + \
                  dfs(mx + 1, oy, rw, uh) + \
                  dfs(ox, my + 1, lw, dh) + \
                  dfs(mx + 1, my + 1, rw, dh)
            g.append(g_)
    return(max(g))

w, h = map(int, input().rstrip().split())
n = int(input())
ml = [[int(x) - 1 for x in input().rstrip().split()] for _ in range(n)]

print(dfs(0, 0, w, h))