#!/usr/bin/env python3
from math import sin, pi
A, B, C = map(int, input().split())


def f(t):
    return A * t + B * sin(C * t * pi)


ok = 0
ng = 101
while abs(f(ok) - 100) > 10**(-6):
    m = (ok + ng) / 2
    if f(m) <= 100:
        ok = m
    else:
        ng = m

print(ok)