#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from fractions import gcd

def readln(ch):
    _res = list(map(int,str(input()).split(ch)))
    return _res

def count(a):
    odd, even = 0,0
    for x in a:
        if x % 2 == 1: odd = odd + 1
        else: even = even + 1
    return odd,even

def deal(n,a):
    odd,even = count(a)
    if even == 0:
        return False
    if even % 2 == 1:
        return True
    if odd > 1:
        return False
    if a[0] % 2 == 0:
        res = a[0]
    else:
        res = a[1]
    for i in range(0,n):
        if a[i] % 2 == 1:
            if a[i] == 1: return False
            a[i] = a[i] - 1
        res = gcd(a[i],res)
    return not deal(n,list(map(lambda x: x//res,a)))

n = int(input())
a = readln(' ')
if deal(n,a):
    print('First')
else:
    print('Second')