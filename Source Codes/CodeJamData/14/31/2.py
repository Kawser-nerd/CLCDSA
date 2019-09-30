import sys
from fractions import gcd

def readints():
    line = sys.stdin.readline().split('/')
    return [int(x) for x in line]
def readstrs():
    return sys.stdin.readline().split()

T, = readints()
for testcase in range(1,T+1):
    P,Q, = readints()
    gg = gcd(P,Q)
    Q /= gg
    P /= gg
    #print repr(Q)
    cnt = "impossible"
    for gen in range(1, 41):
        if 2**gen * P >= Q:
            cnt = gen
            break

    for gen in range(1, 41):
        if 2**gen == Q:
            break
    else:
        cnt = "impossible"

    print "Case #%d: %s" % (testcase, cnt)

