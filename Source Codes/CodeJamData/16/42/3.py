
import sys

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

#sys.stdin = open('B-small-attempt0.in')

import numpy as np

def getPTie(P):
    poly = np.ones(1, dtype=np.float128)
    for p in P:
        poly = np.convolve(poly, [1-p, p])
    #print
    #print P
    #print poly
    #print
    return poly[len(P)/2]

T = getInt()
for caseNo in xrange(1,T+1):
    N, K = getInts()
    P = np.array(sorted([np.float128(w) for w in getWords()]))
    #print K, P
    
    maxPTie = np.float128(0)
    for i in xrange(K+1):
        maxPTie = max(maxPTie, getPTie(
            np.concatenate([P[:i], P[i+N-K:]]) ) )
    
    print "Case #%d: %.9f"%(caseNo, maxPTie)

