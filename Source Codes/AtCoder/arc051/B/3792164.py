#!/usr/bin/env python3
K = int(input())
a = [1, 1]
for i in range(K):
    a[0] += a[-1]
    a = a[::-1]
print(a[-1], a[0])