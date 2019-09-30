#!/usr/bin/env python3
r, c, d = map(int, input().split())
li = []
if d % 2 == 0:
    for i in range(r):
        if i % 2 == 0:
            a = list(map(int, input().split()))
            a = a[:min(c, max(0,d+1-i)):2]
        else:
            a = list(map(int, input().split()))
            a = a[1:min(c, max(0,d+1-i)):2]
        if len(a) > 0:
            li += a
else:
    for i in range(r):
        if i % 2 == 0:
            a = list(map(int, input().split()))
            a = a[1:min(c, max(0,d+1-i)):2]
        else:
            a = list(map(int, input().split()))
            a = a[:min(c, max(0,d+1-i)):2]
        if len(a) > 0:
            li += a

print(max(li))