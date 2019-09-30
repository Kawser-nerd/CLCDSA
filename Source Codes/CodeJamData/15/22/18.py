#!/usr/bin/python2.7

import math

f = open('input.txt', 'r')
T = int(f.readline())

def solve_even(r, c, n):
    sp = r * c - n
    total = 2 * r * c - r - c

    if r > c:
        t = r
        r = c
        c = t

    if r == 1:
        if sp >= c / 2:
            return 0
        else:
            return total - 2 * sp

    thres1 = int(math.ceil((r - 2) * (c - 2) / 2.0))
    thres2 = int(math.ceil(r * c / 2.0) - 2)

    if sp >= math.floor(r * c / 2.0):
        return 0
    elif sp <= thres1:
        return total - 4 * sp
    elif sp <= thres2:
        return total - 4 * thres1 - 3 * (sp - thres1)
    else:
        return 2

def solve_odd(r, c, n):
    sp = r * c - n
    total = 2 * r * c - r - c


    if r > c:
        t = r
        r = c
        c = t

    if r == 1:
        if sp >= math.ceil(c / 2.0):
            return 0
        else:
            return total - 2 * sp

    thres1 = int(math.ceil((r - 2) * (c - 2) / 2.0))
    thres1_p = int(math.floor((r - 2) * (c - 2) / 2.0))
    thres2 = int(math.ceil((r - 2) * (c - 2) / 2.0)) + r + c - 6
    thres3 = int(math.ceil((r - 2) * (c - 2) / 2.0)) + r + c - 2

    if sp >= math.floor(r * c / 2.0):
        return 0
    elif sp <= thres1:
        return total - 4 * sp
    elif sp <= thres2:
        return total - 4 * thres1 - 3 * (sp - thres1)
    elif sp <= thres3:
        return total - 4 * thres1_p - 3 * (sp - thres1_p)

def solve(r, c, n):
    if r * c % 2 == 0:
        return solve_even(r, c, n)
    else:
        return solve_odd(r, c, n)

for t in range(T):
    (r, c, n) = f.readline().rstrip().split(' ')
    r = int(r)
    c = int(c)
    n = int(n)

    print "Case #" + str(t + 1) + ":",
    print solve(r, c, n)

