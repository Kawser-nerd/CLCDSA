#!/usr/local/bin/python3
import numpy as np

T = int(input())
for test in range(1, T + 1):
    line = input().split()
    s = line[0]
    k = int(line[1])
    s = np.array([{'+': 0, '-': 1}[x] for x in s])
    n = len(s)
    count = 0
    for i in range(n - k + 1):
        if s[i] == 1:
            count += 1
            s[i: i + k] ^= 1
    if np.sum(s) > 0:
        count = 'IMPOSSIBLE'
    print('Case #%d: ' % test, count)
