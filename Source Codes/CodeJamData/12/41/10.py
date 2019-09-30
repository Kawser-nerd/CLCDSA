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
        
def solve_case(D, vines):
    from collections import deque
    import collections
    queue = deque()
    #print vines
    
    queue.append((0, vines[0][0]))
    
    seen = collections.defaultdict(int)
    while queue:
        at, power = queue.popleft()
        #print at, power
        dist, length = vines[at]
        if dist + power >= D:
            return True
        if seen[at] >= power:
            continue
        seen[at] = power
        #moves
        i = at+1
        while i < len(vines) and dist + power >= vines[i][0]:
            new_at, new_power = i, min(vines[i][0] - dist, vines[i][1])
            if seen[new_at] < new_power:
                #print "EV", (new_at, new_power)
                queue.append((new_at, new_power))
            i += 1
                                     
    return False
    
                            
def format_answer(cn, answer):
    return "Case #%d: %s" % (cn, "YES" if answer else "NO")

def parse_input():
    cin = sys.stdin.readline
    N = int(cin())
    #print "CASES", N
    for t in xrange(N):
        #print "T", t
        Z = int(cin())
        #print Z
        vines = [[int(x) for x in cin().strip().split()] for y in xrange(Z)]
        G = int(cin())
        yield (G, vines)
        
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
