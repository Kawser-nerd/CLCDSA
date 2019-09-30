# coding: utf-8
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)

@lru_cache(maxsize = None)
def dfs(ox, oy, w, h):
    g = [0]
    g_ = w + h - 1
    x, y = ox + w - 1, oy + h - 1
    for i, m in enumerate(ml):
        mx, my = m
        if ox <= mx <= x and oy <= my <= y:
            lw, rw, uh, dh = mx - ox, x - mx, my - oy, y - my
            g.append(g_ + \
                dfs(ox, oy, lw, uh) + \
                dfs(mx + 1, oy, rw, uh) + \
                dfs(ox, my + 1, lw, dh) + \
                dfs(mx + 1, my + 1, rw, dh))
    return(max(g))

w, h = map(int, input().rstrip().split())
n = int(input())
ml = [[int(x) - 1 for x in input().rstrip().split()] for _ in range(n)]

print(dfs(0, 0, w, h))