#!/usr/bin/env python3
N, va, vb, L = map(int, input().split())
for _ in range(N):
    t = L / va
    L -= (va - vb) * t
print(L)