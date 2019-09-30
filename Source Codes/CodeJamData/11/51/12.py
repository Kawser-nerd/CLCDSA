import sys
from fractions import Fraction
from fractions import gcd
import multiprocessing
cin = sys.stdin.readline

def solve(upper, lower, G):
    #print G
    uarr = [0] * (upper[-1][0]+1)
    larr = [0] * (upper[-1][0]+1)
    for i in xrange(len(upper)-1):
        for x in xrange(upper[i][0], upper[i+1][0]):
            uarr[x] = upper[i][1] + (x - upper[i][0])*(upper[i+1][1] - upper[i][1])*1.0 / (upper[i+1][0]-upper[i][0])
    for i in xrange(len(lower)-1):
        for x in xrange(lower[i][0], lower[i+1][0]):
            larr[x] = lower[i][1] + (x - lower[i][0])*(lower[i+1][1] - lower[i][1])*1.0 / (lower[i+1][0]-lower[i][0])
    W = len(uarr) - 1
    uarr[W] = upper[-1][1]
    larr[W] = lower[-1][1]
    dd = [uarr[i] - larr[i] for i in xrange(len(uarr))]
    #print dd
    area = sum((dd[i]+dd[i+1]) * 0.5 for i in xrange(W))
    #print area
    need = area*1.0 / (G)
    out = []
    for tt in xrange(1, G):
        findme = tt * need
        #print findme
        aa = 0.0
        for i in xrange(W):
            myarea = 0.5*(dd[i]+dd[i+1])
            #print i, myarea, aa
            if myarea + aa < findme:
                aa += myarea
                continue
            tt = findme - aa
            ll, uu = 0.0, 1.0
            for u in xrange(64):
                mid = (ll+uu) * 0.5
                pp = dd[i]*mid + (dd[i+1]-dd[i])*(mid**2)*0.5
                if pp < tt:
                    ll = mid
                else:
                    uu = mid
            out.append(i + (ll+uu)*0.5)
            break
        else:
            out.append(W)
    return out
                

def procfunc(tup):
    x = solve(*tup[1:])
    print >>sys.stderr, "SOLVE", tup[0]
    return x


if __name__ == '__main__':
    T = int(cin())
    inputs = []
    for cnum in xrange(T):
        W, L, U, G = [int(i) for i in cin().strip().split()]
        A = [tuple(int(i) for i in cin().strip().split()) for j in range(L)]
        B = [tuple(int(i) for i in cin().strip().split()) for j in range(U)]
        
        inputs.append((cnum, B, A, G))

    if False:  #need subprocess??
        pool = multiprocessing.Pool()
        output = pool.map_async(procfunc, inputs, 1).get(999999)
    else:
        output = list(procfunc(x) for x in inputs)

    for i, out in enumerate(output):
        #output processing goes here
        #print >>sys.stderr, cnum
        print "Case #%d:" % (i+1)
        for a in out:
            print a
                    
            
        
    
