#!/usr/bin/env python3


def f(x):
    a = [w[i] * p[i] - w[i] * x for i in range(N)]
    a.sort(reverse=True)
    s = sum(a[:K])
    return s >= 0


N, K = map(int, input().split())
w = [None] * N
p = [None] * N
for i in range(N):
    w[i], p[i] = map(int, input().split())

ok = 0
ng = 100
while ng - ok > 1e-9:
    m = (ok + ng) / 2
    if f(m):
        ok = m
    else:
        ng = m
print(ok)