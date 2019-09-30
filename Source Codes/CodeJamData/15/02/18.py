import sys
import math

t = int(sys.stdin.readline().strip())

for i in range(t):
    d = int(sys.stdin.readline().strip())
    p = [int(k) for k in sys.stdin.readline().strip().split()]

    minm = max(p)
    j = 1
    while j < minm:
        m = 0
        for k in range(d):
            m += (p[k] + j - 1) / j - 1
        minm = min(m + j, minm)
        j += 1

    print "Case #%d: %d" % (i + 1, minm)
