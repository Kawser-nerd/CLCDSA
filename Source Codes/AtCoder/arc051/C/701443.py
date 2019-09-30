#!/usr/bin/env python3
import math
lim = 1000
mod = int(1e9+7)
# input
n, a, b = map(int,input().split())
xs = list(map(int,input().split()))
# calc
lim = min(b, lim)
t = (b - lim) // n
ys = [math.log(x) + math.log(a) * t for x in xs]
zs = [t] * n
for _ in range(b - t * n): # at most lim times
    i = ys.index(min(ys))
    ys[i] += math.log(a)
    zs[i] += 1
# output
ixs = list(range(n))
ixs.sort(key=lambda i: ys[i])
for i in ixs:
    print(xs[i] * pow(a, zs[i], mod) % mod)