import sys
from fractions import gcd
import multiprocessing
cin = sys.stdin.readline

def solve(X, S, R, T, walks):
    def better(length, speed, avail):
        base_time = length * 1.0 / (speed + S)
        if((speed + R)*avail >= length):
            tused = length*1.0/(speed+R)
            return (tused, length * -1.0 / (speed+R) + base_time)
        tused = avail
        a = (length*1.0 - (speed+R)*avail) / (speed + S)
        return (avail, -1*(avail + a) + base_time)
    
    def keyf(tup):
        x = better(tup[0], tup[1], T)
        return (x[1] / x[0], x[0])

    at = 0
    true_walks = []
    for start, end, speed in walks:
        if start != at:
            true_walks.append((start-at, 0))
            at = start
        true_walks.append((end-at, speed))
        at = end
    if at != X:
        true_walks.append((X-at, 0))
    #print >>sys.stderr, true_walks

    out = sum((le*1.0/(speed + S)) for (le, speed) in true_walks)

    while T > 1e-8 and true_walks:
        true_walks.sort(key=keyf)
        #print true_walks
        length, speed = true_walks.pop()
        avail = T
        
        x = better(length, speed, avail)
        out -= x[1]
        
        T = max(0, T - x[0])#min(avail, length * 1.0 / (speed+R)))
        
    
    return out
        
        
        
    
def procfunc(tup):
    x = solve(*tup[1:])
    print >>sys.stderr, "SOLVE", tup[0]
    return x


if __name__ == '__main__':
    T = int(cin())
    inputs = []
    for cnum in xrange(T):
        X, S, R, t, N = [int(i) for i in cin().strip().split()]
        gg = []
        for i in xrange(N):
            B, E, W = [int(i) for i in cin().strip().split()]
            gg.append((B,E,W))
        inputs.append((cnum, X, S, R, t, gg))

    if True:  #need subprocess??
        pool = multiprocessing.Pool()
        output = pool.map_async(procfunc, inputs, 1).get(999999)
    else:
        output = list(procfunc(x) for x in inputs)

    for i, out in enumerate(output):
        #output processing goes here
        #print >>sys.stderr, cnum
        print "Case #%d: %.12lf" % (i+1, out)
                    
            
        
    
