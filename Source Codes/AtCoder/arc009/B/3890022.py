#!/usr/bin/env python3
b = list(map(int, input().split()))
N = int(input())
a = [input() for _ in range(N)]

r = {}
for i, x in enumerate(b):
    r[x] = i

s = []
for n in a:
    x = 0
    for c in n:
        x *= 10
        x += r[int(c)]
    s.append(str(x).zfill(10))

s.sort()
for n in s:
    x = 0
    for c in n:
        x *= 10
        x += b[int(c)]
    print(x)