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
        
def solve_case(levels):
    def key(level):
        
        z, (tim, prob) = level
        
        oo = (-1.0 * ( 1 + (prob/ (1.0 - prob))), z)
        #print z, tim, prob, oo
        return oo
        
    gg = list(enumerate(levels))
    gg.sort(key=key)
    return [i[0] for i in gg]
    
        
    
    
                            
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, ' '.join(str(i) for i in answer))

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        #print "T", t
        Z = int(cin())
        #print Z
        vines = [[int(x) for x in cin().strip().split()] for y in xrange(2)]
        gg = list(zip(vines[0], [x * 0.01 for x in vines[1]]))
        yield (gg,)
        
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
