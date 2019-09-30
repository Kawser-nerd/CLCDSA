import math
import sys
from collections import defaultdict
def ints():
    return [int(x) for x in raw_input().strip().split()]

#line = raw_input().strip()

T, = ints()
for t in range(T):
    N,K = ints()
    tops = []
    sides = []
    pans = []
    for i in range(N):
        r,h = ints()
        side = h * r * 2 # * math.pi
        top = r**2 # * math.pi
        pans.append((side,top))

    pans.sort()

    ret = 0
    largest = 0
    for i in range(N-(K-1), N):
        pan = pans[i]
        largest = max(largest, pan[1])
        ret += pan[0]

        # got to be a better way
    pans = pans[:N-(K-1)]
    #print pans

    ret += largest
    pans2 = []
    for pan in pans:
        pans2.append(pan[0] + max(0, pan[1] - largest))
    
    ret += max(pans2)


    print "Case #%d: %s" % (t+1, ret * math.pi)

    
    
