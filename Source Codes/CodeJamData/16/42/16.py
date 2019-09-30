import sys
import random
import re
import itertools
import math
from collections import Counter
from multiprocessing import Pool

verbose = False


def read():
    # read data for a single test case
    n, k = [int(u) for u in sys.stdin.readline().split()]
    p = [float(u) for u in sys.stdin.readline().split()]
    assert len(p) == n
    
    return n, k, p


def write(res):
    # write answer for a single test case
    print res


def compute(p):
    # compute answer for this array of k elements
    k = len(p)
    assert k % 2 == 0
    
    res = dict()
    for i in xrange(k+1):
        # find the probability of have x YES and y NO in the first i (p[:i])
        for x in xrange(i+1):
            y = i-x
            if i == 0 and x == 0 and y == 0:
                res[(0, 0, 0)] = 1.0
            elif x+y > i:
                res[(i, x, y)] = 0.0
            else:
                assert i > 0
                q = p[i-1]
                r = 0.0
                if x > 0:
                    r += q * res[(i-1, x-1, y)]
                if y > 0:
                    r += (1-q) * res[(i-1, x, y-1)]
                res[(i, x, y)] = r
    
    return res[(k, k/2, k/2)]


def solve(data):
    n, k, p = data
    
    p = sorted(p)
    sol = 0.0
    
    for i in xrange(k+1):
        # try to take i values on the left and k-i on the right
        sol = max(sol, compute(p[:i] + p[n-k+i:]))
    
    
    if verbose:
        sys.stderr.write(".")
        sys.stderr.flush()
    
    return sol


def check(data):
    
    if verbose:
        sys.stderr.write(".")
        sys.stderr.flush()
    
    return res


if __name__ == '__main__':
    check_mode = False
    parallelize = False
    
    if len(sys.argv) > 1 and "-v" in sys.argv[1:]:
        verbose = True
    
    if len(sys.argv) > 1 and "-c" in sys.argv[1:]:
        check_mode = True
    
    if len(sys.argv) > 1 and "-p" in sys.argv[1:]:
        parallelize = True
        i = sys.argv.index("-p")
        if len(sys.argv) > i+1 and sys.argv[i+1].isdigit():
            processes = int(sys.argv[i+1])
        else:
            processes = 2
        
    t = int(sys.stdin.readline())
    if verbose:
        print >> sys.stderr, "Solving %d test cases" % t
    
    # read input
    test_cases = [read() for i in xrange(t)]
    
    # solve
    if parallelize:
        process_pool = Pool(processes=processes)
        if check_mode:
            test_results = process_pool.map_async(check, test_cases).get(9999999)
        else:
            test_results = process_pool.map_async(solve, test_cases).get(9999999)
    
    else:
        if check_mode:
            test_results = [check(data) for data in test_cases]
        else:
            test_results = [solve(data) for data in test_cases]
    
    if verbose:
        sys.stderr.write("\n")
        sys.stderr.flush()
    
    # write output
    for i, res in enumerate(test_results):
        print "Case #%d:" % (i+1),
        write(res)


