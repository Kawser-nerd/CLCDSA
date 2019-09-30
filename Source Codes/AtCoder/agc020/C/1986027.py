#!/usr/bin/env python3
import math
input()
dp = 1
for x in map(int, input().split()):
    dp |= dp << x
h = math.ceil((len(format(dp, 'b')) - 1) / 2)
print(h + bin(dp >> h)[::-1].index('1'))