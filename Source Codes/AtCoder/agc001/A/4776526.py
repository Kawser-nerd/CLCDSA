#!/usr/bin/env python3

N = int(input())
L = []
for n in [int(i) for i in input().split()]:
    L.append(n)

L.sort()
SUM = 0
for i in range(N):
    x = L.pop()
    y = L.pop()
    if x < y:
        SUM = SUM + x
    elif x >= y:
        SUM = SUM + y

print(SUM)