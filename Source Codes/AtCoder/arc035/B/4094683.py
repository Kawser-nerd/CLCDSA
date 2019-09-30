#!/usr/bin/env python3
from itertools import accumulate
from collections import Counter
from math import factorial

MOD = 10 ** 9 + 7

N = int(input())
T = [int(input()) for _ in range(N)]
T.sort()

cs = list(accumulate(T))
print(list(accumulate(cs))[-1])

way = 1
cnt = Counter(T)
for v in cnt.values():
    way *= factorial(v)
    way %= MOD
print(way)