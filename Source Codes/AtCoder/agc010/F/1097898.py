#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from fractions import gcd

def readln():
    _res = list(map(int,str(input()).split(' ')))
    return _res

def calc(x,line):
    if line == 0:
        for l in v[x]:
            if e[l][0] == x: son = e[l][1]
            else: son = e[l][0]
            if a[son-1] < a[x-1] and calc(son,l) == -1:
                return 1
        return -1
    else:
        if e[line][0] == x: y = 0
        else: y = 1
        if f[line][y] != 0: return f[line][y]
        for l in v[x]:
            if l != line:
                if e[l][0] == x: son = e[l][1]
                else: son = e[l][0]
                if a[son-1] < a[x-1] and calc(son,l) == -1:
                    f[line][y] = 1
                    return 1
        f[line][y] = -1
        return -1

n = int(input())
v = [set([]) for i in range(0,n+1)]
e = [0 for i in range(0,n)]
a = readln()
for i in range(1,n):
    s = readln()
    v[s[0]].add(i)
    v[s[1]].add(i)
    e[i] = s

f = [[0,0] for i in range(0,n)]
ans = []
for i in range(1,n+1):
    if calc(i,0) == 1:
        ans.append(i)
ans = list(map(str,ans))
print(' '.join(ans))