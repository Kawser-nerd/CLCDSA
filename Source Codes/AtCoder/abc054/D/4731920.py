# -*- coding: utf-8 -*-
import itertools
import sys
import math
from functools import lru_cache

# 1??
# n = int(input())

# ?????2??
from queue import Queue

n, a, b = list(map(int, input().split()))

ll = [[-1 for i in range(401)] for j in range(401)]

# queue = Queue()
ll[0][0] = 0
for i in range(n):
    ap, bp, price = list(map(int, input().split()))
    #    next = Queue()
    #    for q in queue:
    #        ll[q[0] + ap][q[1] + bp] = min(ll[q[0]][q[1]] + price, ll[q[0] + ap][q[1] + bp])
    #        next.put_nowait([q[0] + ap, q[1] + bp])
    for aa in reversed(range(390)):
        for bb in reversed(range(390)):
            if ll[aa][bb] >= 0:
                if ll[aa + ap][bb + bp] < 0:
                    ll[aa + ap][bb + bp] = 99999
                ll[aa + ap][bb + bp] = min(ll[aa + ap][bb + bp], ll[aa][bb] + price)
              #  print(aa+ap,bb+bp,ll[aa+ap][bb+bp])
ret = 9999999
for aa in range(401):
    for bb in range(1, 401):
        if abs(float(aa) / bb - float(a) / b) < 0.001 and ll[aa][bb] > 0:
            ret = min(ret, ll[aa][bb])
if ret > 900000:
    print('-1')
else:
    print(ret)