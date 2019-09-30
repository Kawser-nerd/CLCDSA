# -*- coding: utf-8 -*-
"""
Contents   : AtCoder Regular Contest 094 d?? WA
Author     : Kitaura Hiromi
LastUpdate : 20180414
Since      : 20180414
Comment    : ?????????????????
"""
from math import ceil, sqrt

Q = int(input())
for i in range(Q):
    A, B = sorted(map(int, input().split(" ")))
    s = A*B

    if A == B:
        print(2*A - 2)
    elif A == B + 1:
        print(2*A - 2)
    else:
        C = ceil(sqrt(s)) - 1
        if C*(C+1) >= s:
            print(2*C - 2)
        else:
            print(2*C - 1)