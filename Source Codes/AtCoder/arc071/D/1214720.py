#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import *

def readln():
    _res = list(map(int,str(input()).split(' ')))
    return _res

p = 1000000000 + 7

n = readln()[0]
f = [0 for i in range(0,n+10)]
f[1] = n
f[2] = n * n
s = f[:]
s[2] = f[1] + f[2]
for i in range(3,n+1):
    f[i] = f[i-1] + (n - 1) * (n - 1)
    f[i] = f[i] + s[i - 3] + (n - i + 2)
    f[i] = f[i] % p
    s[i] = s[i - 1] + f[i]
    s[i] = s[i] % p
print(f[n])