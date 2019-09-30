#!/usr/bin/env python3
r, c, d = map(int, input().split())
li = []
for i in range(r):
    a = list(map(int, input().split()))
    a = a[range(2)[d%2 != i%2]:min(c, max(0, d+1-i)):2]
    if len(a) > 0: li += a

print(max(li))