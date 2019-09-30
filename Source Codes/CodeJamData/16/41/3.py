import sys

def getWords():
    return sys.stdin.readline().strip().split()

def getInts():
    return [int(i) for i in getWords()]

def getInt():
	i = getInts()
	assert len(i)==1
	return i[0]

#sys.stdin = open('A.in')

stored = dict()
beats = {'P':'R', 'R':'S', 'S':'P'}
def getFirst(n, c):
    if (n,c) in stored:
        return stored[(n,c)]
    if n==0:
        ans = c
    else:
        a = getFirst(n-1, c)
        b = getFirst(n-1, beats[c])
        if a < b:
            ans = a+b
        else:
            ans = b+a
    stored[(n,c)] = ans
    return ans

T = getInt()
for caseNo in xrange(1,T+1):
    
    N, R, P, S = getInts()
    
    p = []
    r = []
    s = []
    good = True
    for i in xrange(N):
        p.append(P)
        r.append(R)
        s.append(S)
        h = (P+R+S)//2
        P, R, S = (h-S, h-P, h-R)
        if (min(P, R, S) < 0):
            good = False
            break
    if good:
        assert P+R+S == 1
        if P==1:
            last = 'P'
        elif R==1:
            last = 'R'
        else:
            last = 'S'
        answer = getFirst(N, last)        
    else:
        answer = 'IMPOSSIBLE'
    print "Case #%d: %s"%(caseNo, answer)

