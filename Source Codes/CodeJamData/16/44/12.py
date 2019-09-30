import sys
import random
import re
import itertools
import math
from collections import Counter
from multiprocessing import Pool

from pulp import *

verbose = False


def read():
    # read data for a single test case
    n = int(sys.stdin.readline())
    c = [[int(u) for u in sys.stdin.readline().replace('\n','')] for i in xrange(n)]
    
    return n, c


def write(res):
    # write answer for a single test case
    print res


def solve(data):
    n, c = data
    
    
    # x = {(i,j): LpVariable("x_%d_%d" % (i, j), lowBound=c[i][j], upBound=c[i][j], cat="Integer") for i in xrange(n) for j in xrange(n)}
    
    sol = n**2 + 5
    
    for s in itertools.product([0, 1], repeat=n**2):
        cc = [[s[i*n+j] for i in xrange(n)] for j in xrange(n)]
        if any(cc[i][j] < c[i][j] for i in xrange(n) for j in xrange(n)):
            continue
        
        if sum(cc[i][j] for i in xrange(n) for j in xrange(n)) >= sol:
            continue
        
        good = True
    
        for i in xrange(n):
            prob = LpProblem("myProblem", LpMaximize)
            
            f = {(j,k): LpVariable("f_%d_%d" % (j, k), lowBound=0, upBound=(0 if k==i else min(cc[k][j], cc[i][j])), cat="Integer") for j in xrange(n) for k in xrange(n)}
            
            for j in xrange(n):
                prob += LpAffineExpression([(f[(j,k)], 1) for k in xrange(n)]) <= 1
            
            for k in xrange(n):
                prob += LpAffineExpression([(f[(j,k)], 1) for j in xrange(n)]) <= 1
            
            prob.setObjective(LpAffineExpression([(v,1) for v in f.itervalues()]))
            
            status = prob.solve()
            assert LpStatus[status] == "Optimal"
            
            flow = int(sum(value(v) for v in f.itervalues()))
            
            if flow >= sum(cc[i][j] for j in xrange(n)):
                # not good!
                good = False
                break
        
        if good:
            sol = min(sol, sum(cc[i][j] for i in xrange(n) for j in xrange(n)))
    
    res = sol - sum(c[i][j] for i in xrange(n) for j in xrange(n))
    
    if verbose:
        sys.stderr.write(".")
        sys.stderr.flush()
    
    return res


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


