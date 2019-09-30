#import string,itertools,fractions,heapq,re,array,bisect
#from math import *
#from collections import Counter
def rl(s): return xrange(len(s))


INF = 2147483647


import sys
stdin = sys.stdin

T =        int( stdin.readline().strip() )

for icase in range(1, T+1):
    D, N = map(int, stdin.readline().strip().split())
    horses = []
    for i in range(N):
        horses.append(map(int, stdin.readline().strip().split()))
    horses.sort()
    horses.reverse()

    finish = 0
    for start, speed in horses:
        dist = D - start
        time = dist / float(speed)
        finish = max(time, finish)

    print "Case #%d: %.15g" % (icase, D/float(finish))


