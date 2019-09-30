
def xform(n,b):
    s = 0
    while n != 0:
        s += (n % b) ** 2
        n /= b
    return s

def happy(n,b):
    pres = set()
    while n not in pres:
        pres.add(n)
        n = xform(n,b)
    return n == 1

import sys

T = int(sys.stdin.readline())
for i in xrange(T):
    bs = map(int, sys.stdin.readline().split(' '))
    j = 1
    good = False
    while not good:
        j += 1
        good = True
        for b in bs:
            if not happy(j,b):
                good = False
                break
    print 'Case #%d: %d' % (i+1, j)
