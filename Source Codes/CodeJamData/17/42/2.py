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

def print_dot(f):
    def g(*args, **kwargs):
        res = f(*args, **kwargs)
        if verbose:
            sys.stderr.write(".")
            sys.stderr.flush()
        return res
    return g


def read():
    # *only* read data for a single test case
    n, c, m = [int(_) for _ in sys.stdin.readline().split()]
    requests = [[int(_) for _ in sys.stdin.readline().split()] for i in xrange(m)]
    
    return n, c, m, requests


def write(res):
    # write answer for a single test case
    print res[0], res[1]


@print_dot
def solve(data):
    n, c, m, requests = data
    
    res = None
    
    # count number of rides per customer
    rides_per_customer = [0] * c
    for (p, i) in requests:
        rides_per_customer[i-1] += 1
    
    rides_per_place = [0] * n
    for (p, i) in requests:
        rides_per_place[p-1] += 1
    
    
    for k in xrange(max(rides_per_customer), m+1):
        # can do in k rides?
        
        upgrades = 0
        to_place = 0
        
        for x in reversed(rides_per_place):
            if x > k:
                # too many people
                upgrades += x-k
                to_place += x-k
            
            elif x < k:
                # can place y people here
                y = min(to_place, k-x)
                to_place -= y
        
        if to_place == 0:
            # there is a solution
            res = k, upgrades
            break
    
    return res


@print_dot
def check(data):
    
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


