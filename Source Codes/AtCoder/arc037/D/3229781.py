#!/usr/bin/env python3
MOD = 10 ** 9 + 7
n = int(input())
x = [ 1, 2, 1 ]
for _ in range(n):
    y = [ None ] * 3
    y[0] = (3 * x[0] + x[1] ** 3) % MOD
    y[1] = (x[1] ** 2 + x[1] * (2 * x[1] * x[2] - x[2] ** 2)) % MOD
    y[2] = (x[1] ** 2 + x[2] * (2 * x[1] * x[2] - x[2] ** 2)) % MOD
    x = y
print(x[0])