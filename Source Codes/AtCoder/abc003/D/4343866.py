# coding: utf-8
from math import factorial as fact
from functools import lru_cache

div = int(1e9 + 7)

@lru_cache(maxsize = None)
def iCj(i, j):
    if i < j:
        return(0)
    return(fact(i) // (fact(j) * fact(i - j)))

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