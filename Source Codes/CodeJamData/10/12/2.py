import sys, os
from math import *

T = int(sys.stdin.readline())

INF = 999999999

def inrange(x, l, h):
    if l > h:
        l, h = h, l
    if x < l or x > h:
        return False
    return True

for _t in xrange(T):
    D, I, M, N = map(int, sys.stdin.readline().split())
    nums = map(int, sys.stdin.readline().split())

    if N == 1:
        print "Case #%d: 0" % (_t+1)
        continue

    ninsert = [0]
    _m = 0
    if M == 0:
        ninsert.extend([INF]*255)
    else:
        while len(ninsert) < 256:
            for i in xrange(M):
                ninsert.append(_m)
            _m += 1

    cheapest = []
    for i in xrange(N+1):
        cheapest.append([INF]*256)
    for i in xrange(256):
        cheapest[0][i] = 0


    for i in xrange(N):
        n = nums[i]
        cn = cheapest[i+1]
        c = cheapest[i]

        for j in xrange(256):
            cn[j] = INF

        themin = 256
        themax = -1
        themin = min(nums[i], themin)
        themax = max(nums[i], themax)
        if i > 0:
            themin = min(nums[i-1], themin)
            themax = max(nums[i-1], themax)
        if i < N-1:
            themin = min(nums[i+1], themin)
            themax = max(nums[i+1], themax)
        for x in xrange(themin, themax+1):
            # ok = False
            # if i > 0:
                # if inrange(x, nums[i], nums[i-1]):
                    # ok = True
            # if i < N-1:
                # if inrange(x, nums[i], nums[i+1]):
                    # ok = True
            # if not ok:
                # continue
            v = abs(x - n)
            for j in xrange(256):
            # for j in xrange(max(0, x-M), min(255,x+M)+1):
                ins = ninsert[abs(x - j)]
                if ins > 0 and M == 0:
                    continue
                cn[x] = min(cn[x], c[j] + v + I * ins)
        for j in xrange(256):
            cn[j] = min(cn[j], c[j] + D)


    best = INF
    for i in xrange(256):
        best = min(best, cheapest[N][i])
    print "Case #%d: %d" % (_t+1, best)
    sys.stdout.flush()
