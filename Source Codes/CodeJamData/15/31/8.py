import sys
import itertools
import math
import collections
import functools

sys.setrecursionlimit(10000)

def inputInts():
    return map(int, raw_input().split())


def solve(R, C, W):
    if W == 1:
        return R*C

    # Shots before the first hit
    res = R * (C//W)

    if C % W == 0:
        return res + W - 1
    else:
        return res + W
    

T = int(raw_input())
for testId in range(T):
    R, C, W = inputInts()
    print "Case #{:d}: {:d}".format(testId+1, solve(R, C, W))
