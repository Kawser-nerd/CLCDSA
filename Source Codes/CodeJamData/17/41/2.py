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
    n, p = [int(_) for _ in sys.stdin.readline().split()]
    g = [int(_) for _ in sys.stdin.readline().split()]
    
    return n, p, g


def write(res):
    # write answer for a single test case
    print res


@print_dot
def solve(data):
    n, p, g = data
    
    numbers = [0] * p
    for i in g:
        numbers[i%p] += 1
    
    res = numbers[0]
    numbers[0] = 0
    
    for i in xrange(1, p):
        while (i == p-i and numbers[i] >= 2) or (i != p-i and numbers[i] >= 1 and numbers[p-i] >= 1):
            numbers[i] -= 1
            numbers[p-i] -= 1
            res += 1
    
    for i in xrange(p):
        while numbers[i] >= p+2:
            x = 1
            numbers[i] -= 1
            while x%p != 0:
                x += 1
                numbers[i] -= 1
            
            res += 1
    
    # print numbers
    assert sum(numbers) <= p+2
    
    things = []
    for (i, x) in enumerate(numbers):
        things += [i] * x
    
    best = 0
    for comb in itertools.permutations(things):
        this_best = 0
        counter = 0
        for i in comb:
            if counter % p == 0:
                this_best += 1
            counter += i
        
        best = max(best, this_best)
    
    res += best
    
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


