import sys, os
from math import *

T = int(sys.stdin.readline())

mem = {}
def wins_slow(a, b):
    if (a, b) in mem:
        return mem[(a,b)]

    if a == b:
        return False
    if a > b:
        return wins_slow(b, a)

    _b = b
    b -= a
    while b > 0:
        if not wins_slow(a, b):
            mem[(a,_b)] = True
            return True
        b -= a
    mem[(a,_b)] = False
    return False

def wins(a,b):
    if a == b:
        return False
    if a > b:
        return wins(b, a)

    if b >= 2 * a:
        return True
    return not wins(b-a, a)

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b%a, a)

phi = .5 * (sqrt(5) + 1)
iphi = 1 / phi

def total_slow(a1, a2, b1, b2):
    t = 0
    for a in xrange(a1, a2+1):
        for b in xrange(b1, b2+1):
            if wins(a,b):
                t += 1
    return t

def intersect(x1, x2, b1, b2):
    if x2 < b1:
        return 0
    if x1 > b2:
        return 0
    return min(x2,b2) - max(x1, b1) + 1

def subtotal(a, b1, b2):
    lose = intersect(int(a * iphi + 1), int(a * phi), b1, b2)
    return b2 - b1 + 1 - lose

def total_fast(a1, a2, b1, b2):
    if a2 - a1 > b2 - b1:
        return total_fast(b1, b2, a1, a2)
    t = 0
    for a in xrange(a1, a2+1):
        t += subtotal(a, b1, b2)
    return t

for _t in range(T):
    a1, a2, b1, b2 = map(int, sys.stdin.readline().split())
    t = total_fast(a1, a2, b1, b2)
    print "Case #%d: %d" % (_t+1, t)
    sys.stdout.flush()
    # t2 = total_slow(a1, a2, b1, b2)
    # print t2
