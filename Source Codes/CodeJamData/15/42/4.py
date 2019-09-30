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

eps = 1e-12

for caseNo in xrange(1,T+1):
    N, V, X = getWords()
    N = int(N); V=np.float128(V); X=np.float128(X)

    C_R_ordered = sorted(
        [ [np.float128(f) for f in getWords()][::-1] for i in range(N) ])
    
    R = np.array([CR[1] for CR in C_R_ordered])
    C = np.array([CR[0] for CR in C_R_ordered]) - X
    
    if C.min() > eps or C.max() < - eps:
        print "Case #%d: IMPOSSIBLE"%(caseNo)
        continue
    
    qRate = C*R
    
    # exploit symmetry
    if qRate.sum() < 0:
        C = - C[::-1]
        R = R[::-1]
        qRate = C*R
    
    cold = (C <= 0)
    hot = ~cold
    
    assert qRate.sum() > -eps
    # more hot than cold: can get all water colder than X
    
    vRateSum = R[cold].sum()
    qRateSum = qRate[cold].sum()

    for hotIx in np.where(hot)[0]:
        if qRateSum + qRate[hotIx] < eps:
            qRateSum += qRate[hotIx]
            vRateSum += R[hotIx]
        else:
            partialQRate = -qRateSum
            partialVRate = partialQRate / C[hotIx]
            qRateSum += partialQRate
            vRateSum += partialVRate
            break
    if not( qRateSum > - eps) or not (vRateSum < R.sum() + eps):
		print >>sys.stderr, vRateSum
		print >>sys.stderr, R.sum()
		print >>sys.stderr, qRateSum
		print >>sys.stderr, C_R_ordered
		print >>sys.stderr, C
		print >>sys.stderr, R
		print >>sys.stderr, hot
		print >>sys.stderr, cold
		assert False

    print "Case #%d: %.9f"%(caseNo, V / vRateSum)
