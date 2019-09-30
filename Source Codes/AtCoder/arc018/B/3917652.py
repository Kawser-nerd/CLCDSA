#!/usr/bin/env python3
from math import floor, ceil
N = int(input())
x = [None] * N
y = [None] * N
for i in range(N):
    x[i], y[i] = map(int, input().split())

ans = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(j + 1, N):
            x1 = x[j] - x[i]
            y1 = y[j] - y[i]
            x2 = x[k] - x[i]
            y2 = y[k] - y[i]
            s = abs(x1 * y2 - x2 * y1)
            if s > 0 and s % 2 == 0:
                ans += 1

print(ans)