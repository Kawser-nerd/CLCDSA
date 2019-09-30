import multiprocessing
import sys
import optparse
import os

def memoized(f):
    se = dict()
    def ret(*args):
        if args in se:
            return se[args]
        x = f(*args)
        se[args] = x
        return x
    return ret

import collections
import random
def solve_case(W, L, radii):
    #swap = False
    #if W < L:
    #    swap = True
    #    L, W = W, L
    #assert W >= L
    sides = collections.Counter(2*i for i in radii)
    keys = reversed(sorted(sides.keys()))
    outs = [None] * len(radii)
    curr = []
    #for key in keys:
    #    num = sides[key]
        #need to put num squares inside!
    for i, r in sorted(enumerate(radii),key=lambda x: x[1], reverse=True):
        while True:
            x, y = random.randint(0, W), random.randint(0, L)
            yay = True
            for xx,yy,rr in curr:
                if abs(xx-x) < r + rr and abs(yy-y) < r + rr:
                    yay = False
                    break
            if yay:
                break
        curr.append((x,y,r))
        #outs.append((x,y))
        outs[i] = (x,y)
                

    return outs
                            
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, ' '.join(' '.join(str(i) for i in z) for z in answer))

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        #print "T", t
        
        N, W, L = [int(x) for x in cin().strip().split()]
        Q = [int(x) for x in cin().strip().split()]
                        
        yield (W,L,Q)
        
def main():
    parser = optparse.OptionParser()
    parser.add_option('--nprocs', type='int', help='parallelize with n procs')
    parser.add_option('--skip', type='int', help='skip this many cases', default=0)
    options, args = parser.parse_args()

    np = options.nprocs
    
    skip = options.skip
    if np is not None:
        pool = multiprocessing.Pool(processes=np)
        procs = []
        cn = 0
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            procs.append((cn, pool.apply_async(solve_case, args=args)))
            cn += 1
        for i, proc in procs:
            ans = proc.get()
            print format_answer(i+1, ans)
    else:
        cn = 0
        #print "OMG"
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            ans = solve_case(*args)
            print format_answer(cn+1, ans)
            cn += 1            

if __name__ == '__main__':
    main()
