# -*- coding: utf-8 -*-
import math
n = int(input())

s = math.ceil(n ** (1/2))

ans = []
for i in range(1, s + 1):
    for j in range(n // i + 1):
        m = n - i * j
        d = abs(i - j)
        ans.append(m + d)
print(min(ans))