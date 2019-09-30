# -*- coding: utf-8 -*-
import itertools
import sys
import math
from functools import lru_cache

# 1??
# n = int(input())

# ?????2??
from queue import Queue
from operator import mul
from functools import reduce

nCr = {}


def cmb(n, r):
    #print("nCr", n, r)
    if r == 0 or r == n: return 1
    if r == 1: return n
    if (n, r) in nCr: return nCr[(n, r)]
    nCr[(n, r)] = cmb(n - 1, r) + cmb(n - 1, r - 1)
    return nCr[(n, r)]


n, a, b = list(map(int, input().split()))

value = list(map(int, input().split()))

# ??????????
value = list(reversed(sorted(value)))

# ????????????????
takai = 0
avg = 0
for i in range(a):
    if value[i] > value[a]:
        takai += 1
    avg += value[i]
# ???A???????????????
avg /= a
print(avg)

cc = value.count(value[a])

# ???????
##????????A??????????a???b???  nCcc???????
if value[0] == value[a]:
    sum = 0
    #print(a, b, cc, min(cc, b) + 1,1)
    for i in range(a, min(cc, b) + 1):
        sum += cmb(cc , i)
    print(sum)
else:
    print(cmb(cc, a - takai))

##????? a-takai?? (b-takai) or cc???????