## code jam round 2
## b. triangle areas

import time
from math import *

start = time.clock()

inputf = open('B-large.in','r')
outputf = open('B-large.out','w')
lines = inputf.readlines()
N = int(lines[0])

def length(A,B):
    return sqrt((A[0]-B[0])**2 + (A[1]-B[1])**2)

def area(A,B,C):
    a = length(B,C)
    b = length(A,C)
    c = length(A,B)
    s = (a+b+c)/2
    return sqrt(s*(s-a)*(s-b)*(s-c))

def reduce_max(N,M):
    if N >= M: return (N-1,M)
    else: return (N,M-1)

def inc_min(N,M,maxN,maxM):
    if N <= M:
        if N+1 <= maxN: return (N+1,M)
        elif M+1 <= maxM: return (N, M+1)
    elif M <= N:
        if M+1 <= maxM: return (N,M+1)
        elif N+1 <= maxN: return (N+1,M)
    else: print 'ERROR!!!!!!!!!!!!!!!!!!'

def process(N,M,A):
    if A > N*M: return 'IMPOSSIBLE'
    maxN, maxM = N, M
    while A <= N*M:
        (N,M) = reduce_max(N,M)
    while A > N*M:
        (N,M) = inc_min(N,M,maxN,maxM)
    # can't reduce either N or M any further
    for x in xrange(N+1):
        for y in xrange(M+1):
            if A == N*M - x*y: return '0 0 %d %d %d %d' % (N,x,y,M)
    return 'IMPOSSIBLE'

for case in xrange(1,N+1):
    [N,M,A] = map(int, lines[case].split())
    out = process(N,M,A)
#    print 'Case #%d: %s' % (case, out)
#    print 'Time elapsed: %d seconds' % (int(time.clock()-start),)
    outputf.write('Case #%d: %s\n' % (case, out))

inputf.close()
outputf.close()

print 'Total time: %d seconds' % (int(time.clock()-start),)
