#!/usr/bin/env python3
import numpy as np
N = int(input())
x = [input() for _ in range(N)]
ans = sum([v.count('x') for v in x])
x = np.array([list(v.replace('x', '.')) for v in x])
for i in range(9):
    seq = list(filter(lambda x: x != '', ''.join(x[:, i]).split('.')))
    ans += len(seq)
print(ans)