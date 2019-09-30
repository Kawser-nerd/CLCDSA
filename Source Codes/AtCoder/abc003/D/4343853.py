# coding: utf-8
from functools import lru_cache

div = int(1e9 + 7)

@lru_cache(maxsize = None)
def iCj(i, j):
    if i < j:
        return(0)
    s = min([j, i - j])
    pi = [0] * (s + 1)   # ????????? i ??
    for ii in range(i + 1):
        if ii == 0:
            pi[0] = 1
        else:
            pii = list(pi)
            for jj in range(s + 1):
                pii[jj] += pi[jj - 1] if jj != 0 else 0
                if pii[jj] == 0:
                    break
                elif pii[jj] >= div:
                    pii[jj] -= div
            # print(pii)
            pi = pii
    return(pi[-1])

numdl = lambda n, d, l: iCj(n, d) * iCj(n - d, l)

def inner(x, y, d, l):
    if x * y == d + l:
        num = iCj(x * y, d)
    else:
        num = numdl(x * y, d, l)
        # ???????????
        num -= numdl(x * (y - 1), d, l) * 2
        num -= numdl((x - 1) * y, d, l) * 2
        # ??????????
        num += numdl(x * (y - 2), d, l)
        num += numdl((x - 2) * y, d, l)
        num += numdl((x - 1) * (y - 1), d, l) * 4
        # ?????????????
        num -= numdl((x - 2) * (y - 1), d, l) * 2
        num -= numdl((x - 1) * (y - 2), d, l) * 2
        # ?????????
        num += numdl((x - 2) * (y - 2), d, l)
    return(num)

# R?C? R * C ??? 1 <= r, c <= 30
r,c = map(int, input().rstrip().split())
# ?????? X * Y ??? 1 <= x <= R, 1 <= y <= C
x,y = map(int, input().rstrip().split())
# d: ???? l: ???? 0 <= d, l, 1 <= D + L <= x * y
d,l = map(int, input().rstrip().split())

# r * c ???? x * y ???????????
# (r - x + 1)(c - y + 1) ??????
area = (r - x + 1) * (c - y + 1)
print(inner(x, y, d, l) * area % div)