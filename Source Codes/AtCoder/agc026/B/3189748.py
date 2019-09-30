# -*- coding: utf-8 -*-

from math import ceil
from fractions import gcd

def solve(A, B, C, D):
    if A < B or D < B: return False
    if A % B > C: return False
    if D % B == 0: return True

    g = gcd(B, D)
    r = A % g  # +D -B ?????? x % g == r ???x????
    # x % g == r and C < x < B ??? x ??????? False ???
    return not (C < B - g + r)

T = int(input())
for i in range(T):
    A, B, C, D = [int(t) for t in input().split()]
    print('Yes' if solve(A, B, C, D) else 'No')