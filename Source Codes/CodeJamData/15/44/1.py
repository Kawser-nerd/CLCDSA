#!/usr/bin/python
__author__ = 'Tianren Liu'

import sys
import numpy as np
from fractions import gcd

def lcm(a, b):
    return (a * b) // gcd(a, b)

def compo(MA,MB):
    M = {}
    for ra,ca in MA.items():
        for rb,cb in MB.items():
            if lcm(ra,rb) in M:
                M[lcm(ra,rb)] += ca*cb*gcd(ra,rb)
            else:
                M[lcm(ra,rb)] = ca*cb*gcd(ra,rb)
    return M

def merge(MA,MB):
    M = MA.copy()
    for rb,cb in MB.items():
        if rb in M:
            M[rb] += cb
        else:
            M[rb] = cb
    return M

cache = {}
def solve_tf(R, C):
    if (R,C) in cache:
        return cache[(R,C)]
    res={}
    if R >= 1:
        res = merge(res, compo(solve_ti(R-1, C), {1:1}))
    if R >= 2:
        if C % 6 == 0:
            res = merge(res, compo(solve_ti(R-2, C), {3:1, 6:1}))
        elif C % 3 == 0:
            res = merge(res, compo(solve_ti(R-2, C), {3:1}))
    if R >= 3:
        if C % 4 == 0:
            res = merge(res, compo(solve_ti(R-3, C), {4:1}))
    cache[(R,C)] = res
    return res

def solve_ti(R, C):
    if R == 0 or R == 2:
        return {1:1}
    if R == 1:
        return {}
    return solve_tf(R-2, C)

def solve(R, C):
    return sum(solve_tf(R,C).values()) + sum(solve_ti(R,C).values())
    
if __name__ == "__main__":
    T = int(sys.stdin.readline())
    for t in xrange(T):
        R, C = map(int, sys.stdin.readline().split())
        print( "Case #{}: {}".format(t+1, solve(R,C) ))