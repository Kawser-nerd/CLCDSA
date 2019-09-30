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
        
gooey = 0
def solve_case(scores):
    Z = sum(scores)
    out = []
    for i,score in enumerate(scores):
        low, high = 0.0, 1.0
        for t in xrange(60):
            mid = (low + high) * 0.5
            my_score = score + Z * mid
            zu = sum(max(0.0, (my_score - qq)*1.0/Z)
                     for (j,qq) in enumerate(scores)
                     if j != i)
            if zu + mid < 1.0:
                #need more
                low = mid
            else:
                high = mid
        out.append(mid * 100.0)
    return out
                            
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, ' '.join(str(x) for x in answer))

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    for t in xrange(N):
        Q = [float(i) for i in cin().strip().split()]
        yield (Q[1:],)
    

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
        for args in parse_input():
            if cn < skip:
                cn += 1
                continue
            ans = solve_case(*args)
            print format_answer(cn+1, ans)
            cn += 1            

if __name__ == '__main__':
    main()
