#!/usr/bin/env python
#coding: utf-8

from sys import stdin, stderr
from math import log10

T = int(stdin.readline())

def rev(N):
    n = N
    ret = 0
    while n > 0:
        ret *= 10
        ret += n % 10
        n = n / 10
        pass
    return ret


def solve(N):
    if N <= 19:
        return N
    else:
        keta = int(log10(N))
        prev = 10**keta - 1
        #keta_up = (keta+1)/2
        keta_dn = keta/2 + 1
        up = rev(N / (10**keta_dn))
        dn = N % (10**keta_dn)
        if dn == 0:
            return solve(N-1) + 1
        elif up == 1:
            return solve(prev) + 1 + dn
        else:
            return solve(prev) + 1 + up + dn

for t in range(T):
    N = int(stdin.readline())
    print "Case #%i:" % (t+1),
    print solve(N)
