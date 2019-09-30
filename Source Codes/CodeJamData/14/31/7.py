from fractions import *

def isDeg2(n):
    k = 0
    while n%2 == 0:
        n /= 2
        k += 1
    return n == 1

def solve(f):
    if not isDeg2(f.denominator):
        return "impossible"
    l, k = Fraction(1, 2), 1
    while l > f:
        l /= 2
        k += 1
    return str(k)

T = int(raw_input())
for z in xrange(T):
    dn = map(int, raw_input().split('/'))
    print "Case #%d: %s" % (z+1, solve(Fraction(dn[0], dn[1])))