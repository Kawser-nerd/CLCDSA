import sys
import random
from itertools import permutations

import operator

class Hiker:
    def __init__(self, d, m):
        self.d = d
        self.m = m
        
        self.first = (360-self.d) * self.m
        self.step = 360 * self.m
    
    def __le__(self, other):
        return self.first <= other.first
    
    def __repr__(self):
        return u'Hiker (%d, %d)' % (self.first, self.step)
        
    def encounters(self, pos):
        if pos < self.first:
            return 1
        
        # print pos, self.first, self.step
        return int( float(pos - self.first)/float(self.step) )



hikers = []

def solve():
    hikers = []
    n = int(sys.stdin.readline())
    for j in xrange(n):
        d, h, m = [int(x) for x in sys.stdin.readline().split()]
        for k in xrange(h):
            hikers.append(Hiker(d,m+k))
    
    hikers = sorted(hikers, key=operator.attrgetter('first'))
    # print hikers
    
    best = len(hikers)
    current = len(hikers)
    
    for hik in hikers:
        # Supero hiker hik
        position = float(hik.first)+0.5
        # print position
        current = sum([ hiker.encounters(position) for hiker in hikers ])
        
        # print [ hiker.encounters(position) for hiker in hikers ]
        best = min(current, best)
    
    print best


t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

