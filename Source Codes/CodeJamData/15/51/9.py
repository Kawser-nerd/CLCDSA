import sys

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

from Queue import Queue

T = getInt()

for caseNo in xrange(1,T+1):
    N, D = getInts()
    S0,As,Cs,Rs = getInts()
    M0,Am,Cm,Rm = getInts()
    
    S = [0]*N
    M = [0]*N
    S[0] = S0
    m = M0
    for i in xrange(1,N):
        S[i] = (S[i-1]*As + Cs) % Rs
        m = (m*Am + Cm) % Rm
        M[i] = m % i
    
    #print M
    #print S
    
    mn = [0]*N
    mx = [0]*N
   
    changes = []
    
    for i in xrange(N):
        if i > 0:
            mn[i] = max(mn[M[i]], S[i] - D)
            mx[i] = min(mx[M[i]], S[i] + 1)
        else:
            mn[i] = S[i] - D
            mx[i] = S[i] + 1

        #print i, mn[i], mx[i]
        if (mn[i] < mx[i]):
            changes.append( (mn[i], 1) )
            changes.append( (mx[i], -1) )
    
    #print sorted(changes)
    changes = [c[1] for c in sorted(changes)]
    s = 0
    mxsum = 0
    for i in changes:
        s += i
        if s > mxsum:
            mxsum = s
    
    print "Case #%d: %d"%(caseNo, mxsum)
