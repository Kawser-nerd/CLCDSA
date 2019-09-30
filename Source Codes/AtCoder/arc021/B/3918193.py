#!/usr/bin/env python3
L = int(input())
B = [int(input()) for _ in range(L)]

t = 0
for x in B:
    t ^= x
if t != 0:
    print(-1)
    exit()

print(t)
for x in B[:-1]:
    t ^= x
    print(t)