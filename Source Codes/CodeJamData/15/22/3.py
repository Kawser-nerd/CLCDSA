import sys
import random
from itertools import permutations


def solve():
    r, c, n = [int(x) for x in sys.stdin.readline().split()]
    
    whites = r*c-n
    
    walls = (r-1)*c + (c-1)*r
    
    if r==1 or c==1:
        a = max(r,c)
        
        if a%2 == 0:
            twos = a/2-1
            ones = 1
        else:
            twos = int(a/2)
            ones = 0
        
        # print ones, twos
        
        k = min(whites, twos)
        whites -= k
        walls -= 2*k
        
        k = min(whites, ones)
        whites -= k
        walls -= 1*k
        
        print walls
        return
        
    
    if (r*c) % 2 == 0:
        fours = (r-2)*(c-2)/2
        threes = r+c-4
        twos = 2
        
        # print fours, threes, twos
        
        k = min(whites, fours)
        whites -= k
        walls -= 4*k
        
        k = min(whites, threes)
        whites -= k
        walls -= 3*k
        
        k = min(whites, twos)
        whites -= k
        walls -= 2*k
        
        print walls
    
    else:
        # First possibility
        fours = int((r-2)*(c-2)/2)
        threes = r+c-2
        twos = 0
        
        k = min(whites, fours)
        whites -= k
        walls -= 4*k
        
        k = min(whites, threes)
        whites -= k
        walls -= 3*k
        
        k = min(whites, twos)
        whites -= k
        walls -= 2*k
        
        first = walls
        
        # Second possibility
        
        whites = r*c-n
        walls = (r-1)*c + (c-1)*r
        
        fours = int((r-2)*(c-2)/2)+1
        threes = r+c-6
        twos = 4
        
        k = min(whites, fours)
        whites -= k
        walls -= 4*k
        
        k = min(whites, threes)
        whites -= k
        walls -= 3*k
        
        k = min(whites, twos)
        whites -= k
        walls -= 2*k
        
        second = walls
        
        print min(first, second)


t = int(sys.stdin.readline())
for i in xrange(t):
    print "Case #%d:" % (i+1),
    solve()

