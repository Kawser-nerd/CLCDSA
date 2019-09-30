#!/usr/bin/env python

for ti in range(int(input())):
    D, N = map(int, input().split())
    v = 1e100
    for i in range(N):
        K, S = map(int, input().split())
        v = min(v, S * D / (D - K))
    print("Case #%d: %.12f" % (ti + 1, v))
