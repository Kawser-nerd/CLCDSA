#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
agc016 B
"""

from collections import Counter

n = int(input())
acnt = Counter(map(int, input().split()))

if len(acnt) > 2:
    print('No')
    exit()

if len(acnt) == 1:
    [(a, nn)] = acnt.most_common(1)
    if a in range(1, n//2+1) or a == n-1:
        print('Yes')
    else:
        print('No')
    exit()

if len(acnt) == 2:
    [(a1, n1), (a2, n2)] = sorted(acnt.most_common(2), key=lambda x: x[0])
    if a2-a1 != 1:
        print('No')
    else:
        if 1 <= a2 - n1 <= (n-n1)//2:
            print('Yes')
        else:
            print('No')