## code jam round 3
## endless knight

import time
from math import *

start = time.clock()

inputf = open('D-small-attempt1.in','r')
outputf = open('D-small1.out','w')
lines = inputf.readlines()
N = int(lines[0])
marker = 1

def binom(n,k,mod=10007):
    if not k: return 1
    elif not n or k > n: return 0

    numer, denom = 1, 1
    k = min(k,n-k)
    for i in range(1,k+1):
        numer *= (n-k+i)
        denom *= i
    res = numer / denom
    return res % mod

def right_down(x,y):
    if (2*x-y)%3 or (2*y-x)%3: return -1
    return ((2*x-y)/3, (2*y-x)/3)

def process(H,W,R,rocks):
    table = [[0]*W for r in range(H)]
    table[0][0] = 1
    for r in range(H):
        for c in range(W):
            if [r+1,c+1] in rocks: table[r][c] = 0
            elif r > 2*c or c > 2*r: table[r][c] = 0
            else:
                u = (r-1,c-2)
                l = (r-2,c-1)
                if u[0] >= 0 and u[1] >= 0:
                    table[r][c] += table[u[0]][u[1]]
                if l[0] >= 0 and l[1] >= 0:
                    table[r][c] += table[l[0]][l[1]]
    return table[H-1][W-1] % 10007

for case in xrange(1,N+1):
    [H,W,R] = map(int, lines[marker].split())
    rocks = [map(int, lines[marker+1+i].split()) for i in range(R)]
    marker += R + 1
    out = process(H,W,R,rocks)
    print 'Case #%d: %s' % (case, out)
    outputf.write('Case #%d: %s\n' % (case, out))

inputf.close()
outputf.close()

print 'Total time: %d seconds' % (int(time.clock()-start),)
