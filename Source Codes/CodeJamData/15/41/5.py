import sys
import numpy as np
from numpy import *

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return array([int(i) for i in getWords()], dtype=int)

def getInt():
	i = getInts()
	assert len(i)==1
	return i

T = getInt()

for caseNo in xrange(1,T+1):
    R, C = getInts()
    symbol = np.array([ [ch for ch in getWords()[0]] for i in range(R) ])
    isTurn = (symbol != '.')
    assert isTurn.shape == (R,C)

    possibleTurn = dict(
        [ (d, np.ones_like(isTurn)) for d in '<>^v' ] )
    
    for r in range(R):
        if not isTurn[r].any(): continue
        c0 = np.where(isTurn[r])[0][0]
        c1 = np.where(isTurn[r])[0][-1]
        possibleTurn['<'][r,c0]=False
        possibleTurn['>'][r,c1]=False
    
    for c in range(C):
        if not isTurn[:,c].any(): continue
        r0 = np.where(isTurn[:,c])[0][0]
        r1 = np.where(isTurn[:,c])[0][-1]
        possibleTurn['^'][r0,c]=False
        possibleTurn['v'][r1,c]=False
    
    isPossible = np.logical_or.reduce([possibleTurn[k] for k in possibleTurn]).all()
    
    if isPossible:
        nChange = 0
        for (r,c) in zip(*np.where(isTurn)):
            nChange += ~possibleTurn[symbol[r,c]][r,c]
        print "Case #%d: %d"%(caseNo, nChange)
    else:
        print "Case #%d: IMPOSSIBLE"%(caseNo)
