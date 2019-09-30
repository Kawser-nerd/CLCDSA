#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def readln():
    _res = list(map(int,str(input()).split(' ')))
    return _res

n = int(input())
a = readln()
c = sorted([[-a[i],i]for i in range(0,n)])
ans = [0 for i in range(0,n)]
front = c[0][1]
for i in range(1,n):
    ans[front] = ans[front] + i * (c[i][0] - c[i-1][0])
    if front > c[i][1]:
        front = c[i][1]

ans[front] = ans[front] + n * (-c[n-1][0])
for a in ans:
    print(a)