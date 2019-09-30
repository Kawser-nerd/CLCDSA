from sys import *
from numpy import *

def solve(T, N, P):
    count = zeros(N)
    result = ''
    for i in range(N):
        count[i] = int(P[i])

    while count.sum() > 0:
        maxBool = (count == count.max())
        maxIndex = array(range(N))[maxBool]
        if maxBool.sum() != 2:
            maxIndex = [maxIndex[0]]
            
        for index in maxIndex:
            result += chr(ord('A') + index)

        result += ' '
        count[maxIndex] -= 1
        
    print "Case #%d: %s" %(T+1, result)

cases = int(raw_input())
for T in xrange(cases):
    N = int(raw_input())
    P = raw_input().split()
    solve(T, N, P)
