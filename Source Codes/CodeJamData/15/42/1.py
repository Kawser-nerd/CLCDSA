from sys import stdin, stderr

# Minimize max(T_i) given 
# sum_i R_iT_i = X
# sum_i R_iT_iC_i = XV

def getInt():
    return int(stdin.readline())

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

def getFloats():
    return tuple(float(z) for z in stdin.readline().split())

from pulp import *

numCases = getInt()
for case in xrange(1, 1+numCases):
    (N, V, X) = getFloats()
    N = int(N)
    print >>stderr, ("Case %d has %d variables" % (case, N))
    sources = [getFloats() for i in xrange(N)]
    sources = [(z[0],z[1]-X) for z in sources]
    sources = sorted([(z[0]*z[1],z[0]) for z in sources])
    if max(z[0] for z in sources) < 0 or min(z[0] for z in sources) > 0:
        ans = "IMPOSSIBLE"
    else:
        vopt = sum(z[1] for z in sources)
        for source in sources:
            if source[0] != 0:
                k = source[1] / source[0]
                v = sum(z[1]-k*z[0] for z in sources if z[1]>k*z[0])
                vopt = min(v,vopt)
        ans = V / vopt
    print "Case #%d: %s" % (case, ans)
