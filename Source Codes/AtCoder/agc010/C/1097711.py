#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def readln(ch):
    _res = list(map(int,str(input()).split(ch)))
    return _res

n = int(input())
a = readln(' ')
e = [set([]) for i in range(0,n+1)]
for i in range(1,n):
    s = readln(' ')
    e[s[0]].add(s[1])
    e[s[1]].add(s[0])
rt = 1
now = n
v = [0 for i in range(0,n+1)]
q = v[:]
q[now] = rt
v[rt] = 1
for i in range(1,n):
    s = q[n-i+1]
    for p in e[s]:
        if v[p] == 0:
            v[p] = 1
            now = now - 1
            q[now] = p

res = 'YES'
up = [0 for i in range(0,n+1)]
for i in range(1,n+1):
    k = q[i]
    if len(e[k]) == 1:
        sum = a[k-1]
    else:
        sum = a[k-1] * 2
    up[k] = sum
    for son in e[k]:
        up[k] = up[k] - up[son]
        if up[son] > a[k-1] and len(e[k]) > 1: res = 'NO'
    if up[k] < 0:
        res = 'NO'
    if len(e[k]) > 1 and up[k] > a[k-1]:
        res = 'NO'

if up[rt] != 0 : res = 'NO'
print(res)