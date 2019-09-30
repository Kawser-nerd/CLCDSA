#!/usr/bin/env python
N, T = map(int, input().split())
B = [[int(i) for i in input().split()] for i in range(N)]

m = [e[0] for e in B if e[1] <= T]

if len(m) == 0:
    print('TLE')
else:
    print(min(m))