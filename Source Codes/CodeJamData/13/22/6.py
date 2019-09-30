#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Uses https://github.com/rkistner/contest-algorithms

import sys, math


def ncr(n, r):
    """ n choose r """
    return math.factorial(n) // math.factorial(r) // math.factorial(n - r)

def probability(height, diamonds):
    ways = 0
    for i in range(height, diamonds+1):
        ways += ncr(diamonds, i)
    return ways / (2**diamonds)

fin = sys.stdin
T = int(fin.readline())
for case in range(1,T+1):
    N, X, Y = map(int, fin.readline().split())

    seq = (abs(X) + Y) // 2

    remaining = N
    for i in range(seq):
        diamonds = i * 4 + 1
        remaining -= diamonds
    sidelen = seq * 2 + 1
    diamonds = seq * 4 + 1
    prob = 0.0
    if remaining >= diamonds:
        prob = 1.0
    elif remaining <= 0:
        prob = 0.0
    else:
        if X == 0:
            # Top diamond
            prob = 0.0
        else:
            if remaining - (sidelen - 1) > Y:
                prob = 1.0
            else:
                prob = probability(Y+1, remaining)

    print("Case #%d: %.10f" % (case, prob))

