#import string,itertools,fractions,heapq,re,array,bisect
#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))


INF = 2147483647


def fail(icase):
    print "Case #%d: IMPOSSIBLE" % icase

def solve2(r, g, letters, icase):
    if r == g:
        print "Case #%d:" % icase, letters*r
    else:
        fail(icase)

import sys
stdin = sys.stdin

T =        int( stdin.readline().strip() )

for icase in range(1, T+1):
    N, r, o, y, g, b, v = map(int, stdin.readline().strip().split())

    if r + g == N:
        solve2(r, g, 'RG', icase)
        continue
    elif y + v == N:
        solve2(y, v, 'YV', icase)
        continue
    elif b + o == N:
        solve2(b, o, 'BO', icase)
        continue

    if 1 < g+1 > r or 1 < v+1 > y or 1 < o+1 > b:
        fail(icase)
        continue
    r1 = 'RG' * g + 'R'
    y1 = 'YV' * v + 'Y'
    b1 = 'BO' * o + 'B'
    r -= g
    y -= v
    b -= o

    have = [(r, "R"), (y, "Y"), (b, "B")]
    have.sort()
    if have[-1][0]*2 > (r + y + b):
        fail(icase)
        continue

    rr = [None] * (r + y + b)
    for i in range(have[-1][0]):
        rr[2*i] = have[-1][1]
    i = len(rr)-1
    mids = have[1][0]
    while mids > 0 and i >= 0:
        if rr[i] is not None:
            i -= 1
            continue
        rr[i] = have[1][1]
        i -= 2
        mids -= 1

    for i in range(len(rr)):
        if rr[i] is None:
            rr[i] = have[0][1]

    for i in range(len(rr)):
        if rr[i] == 'R':
            rr[i] = r1
            break
    for i in range(len(rr)):
        if rr[i] == 'Y':
            rr[i] = y1
            break
    for i in range(len(rr)):
        if rr[i] == 'B':
            rr[i] = b1
            break
    
    print 'Case #%d:' % icase, ''.join(rr)
