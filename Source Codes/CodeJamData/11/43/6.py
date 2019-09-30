import sys
from fractions import gcd
import multiprocessing
cin = sys.stdin.readline

isp = [1]*1000500
isp[0] = isp[1] = 0
LL = len(isp)
prims = []
for i in xrange(2, LL):
    if not isp[i]:
        continue
    prims.append(i)
    j = i*i
    while j < LL:
        isp[j] = 0
        j += i
    
    

def solve(N):
    if(N == 1):
        return 0
    pp = []
    high = 1
    for prim in prims:
        if prim > N:
            break
        p = 1
        q = prim
        while q*prim <= N:
            p += 1
            q *= prim
        high += p
        pp.append(q)
    pp.sort()
    pp = pp[::-1]
    at = 0
    LE = len(pp)
    while at < LE:
        q = pp[at]
        while at+1 < LE and q * pp[at+1] <= N:
            at += 1
            q *= pp[at+1]
        high -= 1
        at += 1
    return high
        
        
        
        
    
def procfunc(tup):
    x = solve(*tup[1:])
    print >>sys.stderr, "SOLVE", tup[0]
    return x


if __name__ == '__main__':
    T = int(cin())
    inputs = []
    for cnum in xrange(T):
        N = int(cin())
        inputs.append((cnum, N))

    if True:  #need subprocess??
        pool = multiprocessing.Pool()
        output = pool.map_async(procfunc, inputs, 1).get(999999)
    else:
        output = list(procfunc(x) for x in inputs)

    for i, out in enumerate(output):
        #output processing goes here
        #print >>sys.stderr, cnum
        print "Case #%d: %d" % (i+1, out)
                    
            
        
    
