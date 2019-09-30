#!/usr/bin/env python3
import math
input()
A = list(map(int, input().split()))

dp = 1
for x in A:
    dp |= dp << x

h = math.ceil(sum(A) / 2)
print(h + bin(dp >> h)[::-1].index('1'))