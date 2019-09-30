#!/usr/bin/env python3
p = complex(*list(map(int, input().split())))
N = int(input())
li = [complex(*list(map(int, input().split()))) for _ in range(N)]
li += [li[0]]
m = min(((p - a) / (b - a)).imag * abs(b - a) for a, b in zip(li, li[1:]))
print(m)