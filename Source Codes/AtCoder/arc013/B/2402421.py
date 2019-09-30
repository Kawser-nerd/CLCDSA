# -*- coding: utf-8 -*-
def inpl(): return map(int, input().split())
C = int(input())
a, b, c = 0, 0, 0
for _ in range(C):
    N, M, L = sorted(inpl())
    a, b, c = max(a, N), max(b, M), max(c, L)

print(a*b*c)