import sys
import random
import re
import itertools
import math
import copy
import bisect
import Queue
from collections import Counter
from multiprocessing import Pool

verbose = False


def read():
    # *only* read data for a single test case
    d, n = [int(u) for u in sys.stdin.readline().split()]
    horses = [[int(u) for u in sys.stdin.readline().split()] for i in xrange(n)]
    
    return d, n, horses


def write(res):
    # write answer for a single test case
    print res


def solve(data):
    d, n, horses = data
    
    res = float(d) / max((float(d) - k) / s for k, s in horses)
    
    print_dot()
    return res


def check(data):
    
    print_dot
    return res


def print_dot():
    if verbose:
        sys.stderr.write(".")
        sys.stderr.flush()

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
            processes = 8
        
    t = int(sys.stdin.readline())
    if verbose:
        print >> sys.stderr, "Solving %d test cases" % t
        for i in xrange(t):
            sys.stderr.write("|" if i%10 == 9 else ".")
        print >> sys.stderr
        sys.stderr.flush()
    
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


