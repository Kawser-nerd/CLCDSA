#!/usr/bin/env python3
from itertools import product
N, M = map(int, input().split())
b = [[int(x) for x in list(input())] for _ in range(N)]
d = [0, 1, 0, -1, 0]
a = [['0'] * M for _ in range(N)]
for i, j in product(range(N)[1:-1], range(M)[1:-1]):
    m = 10
    for dx, dy in zip(d[:-1], d[1:]):
        x = i + dx
        y = j + dy
        m = min(m, b[x][y])
    for dx, dy in zip(d[:-1], d[1:]):
        x = i + dx
        y = j + dy
        b[x][y] -= m
    a[i][j] = str(m)
for x in a:
    print(''.join(x))