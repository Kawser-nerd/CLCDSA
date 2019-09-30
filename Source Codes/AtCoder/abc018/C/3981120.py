#!/usr/bin/env python3
import numpy as np
from itertools import product
R, C, K = map(int, input().split())
s = [input() for _ in range(R)]
cs = np.zeros((R + C + 1, R + C + 1), dtype=np.int16)
for i, j in product(range(R), range(C)):
    if s[i][j] == 'x':
        cs[C + i - j, i + j + 1] = 1
cs = np.cumsum(cs, axis=0)
cs = np.cumsum(cs, axis=1)
ans = 0
k = K - 1
for i, j in product(range(R)[k:-k], range(C)[k:-k]):
    x = C + i - j
    y = i + j + 1
    rec = cs[x + k, y + k]
    rec -= cs[x + k, y - k - 1]
    rec -= cs[x - k - 1, y + k]
    rec += cs[x - k - 1, y - k - 1]
    if rec == 0:
        ans += 1
print(ans)