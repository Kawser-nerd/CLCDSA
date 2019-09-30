#
# Google Code Jam 2010
# Roaund 2: D. Grazing Google Goats
# submission by EnTerr
#

import sys
from time import clock

from math import acos, sin
import psyco
psyco.full()

f = open(sys.argv[1])
def input(): return f.readline().strip();

def getSegmentArea(p, q, t):
    # return the area of circular segment w/center p1, radius determined by q and half-angle by q and p2
    #r = ((p1[0]-q[0])**2 + (p1[1]-q[1])**2) ** .5
    pq = ((p[0]-q[0])**2 + (p[1]-q[1])**2) ** .5
    qt = ((q[0]-t[0])**2 + (q[1]-t[1])**2) ** .5
    pt = ((p[0]-t[0])**2 + (p[1]-t[1])**2) ** .5
    ang = 2*acos((qt**2 - pt**2 - pq**2)/(-2*pq*pt))
    area = pq**2 * (ang - sin(ang))/2
    return area        

def doCase():
    N, M = map(int, input().split())
    p1,p2 = [map(int, input().split()) for _ in range(N)]
    Q = [map(int, input().split()) for _ in range(M)]
    for q in Q:
        print getSegmentArea(p1, q, p2) + getSegmentArea(p2, q, p1),
    print


clk = clock()
for caseNo in xrange(1, int(input())+1):
    print 'Case #%d:' % caseNo,
    doCase()
print >>sys.stderr, 'time= %.1f seconds' % (clock()-clk )

