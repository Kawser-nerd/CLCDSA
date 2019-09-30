#!/usr/bin/env python3

import sys, math, copy
# import fractions, itertools
# import numpy as np
# import scipy

HUGE = 2147483647
HUGEL = 9223372036854775807
ABC = "abcdefghijklmnopqrstuvwxyz"

def each_attend(anm, held):
    n = len(anm)
    m = len(anm[0])
    atte = []
    for i in range(n):
        aim = anm[i]
        for k in aim:
            if k in held:
                break
        atte.append(k)
    return atte

def main():
    n, m = map(int, input().split())
    anm = []
    for i in range(n):
        aim = list(map(int, input().split()))
        anm.append(aim)

    held = set(range(1, m + 1))
    res = HUGE
    while len(held) > 0:
        atte = each_attend(anm, held)
        num_atte = {k: 0 for k in range(1, m + 1)}
        for k in atte:
            num_atte[k] += 1
        ma = max(num_atte.values())
        res = min(res, ma)
        popest_sports = set(filter(lambda k: num_atte[k] == ma, held))
        held -= popest_sports
    print(res)

main()