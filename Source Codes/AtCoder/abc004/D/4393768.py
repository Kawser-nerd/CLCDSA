# coding: utf-8
from functools import lru_cache
import sys
sys.setrecursionlimit(10000)

sb = [-100, 0, 100]

@lru_cache(maxsize = None)
def ops(l, m):
    global marble
    r = l + marble[m] - 1
    if l < sb[m] < r:
        ln = abs(l - sb[m])
        rn = marble[m] - ln - 1
        op = (ln * (ln + 1) + rn * (rn + 1)) // 2
    else:
        ofs = abs(r - sb[m]) if r <= sb[m] else abs(l - sb[m])
        n = marble[m] - 1
        op = (n * (n + 1)) // 2 + ofs * marble[m]
    return(op)

# b: box number
# m: marble color (0:R, 1:G, 2:B)
@lru_cache(maxsize = None)
def plcMbl(b, m):
    if b + sum(marble[m:]) > 500:
        return(float('inf'))
    if m == 3:
        return(0)
    op = ops(b, m)
    opl = [ plcMbl(b + 1, m), op + plcMbl(b + marble[m], m + 1) ]
    return(min(opl))

# 1 <= r, g, b <= 300
marble = list(map(int, input().rstrip().split()))

print(plcMbl(-500, 0))