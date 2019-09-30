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
    n, r, o, y, g, b, v = [int(u) for u in sys.stdin.readline().split()]
    
    return n, r, o, y, g, b, v


def write(res):
    # write answer for a single test case
    print res

def solve_small(r, y, b):
    n = r + y + b
    
    (a, x), (b, y), (c, z) = sorted([(r, 'R'), (y, 'Y'), (b, 'B')])
    # print (a, x), (b, y), (c, z)
    
    assert a <= b <= c
    assert a + b + c == n
    
    if 2*c > n:
        return None
    
    sol = ""
    
    while 2*c < n:
        assert n >= 1
        assert c >= b >= a >= 1
        sol += z + y + x
        
        a -= 1
        b -= 1
        c -= 1
        n -= 3
    
    assert 2*c == n
    assert a + b == c
    sol += (z + y) * b + (z + x) * a
    
    return sol



def solve(data):
    n, r, o, y, g, b, v = data
    
    if r + g == n and r == g:
        print_dot()
        return "RG" * r
    
    if y + v == n and y == v:
        print_dot()
        return "YV" * y
    
    if b + o == n and b == o:
        print_dot()
        return "BO" * b
    
    if v >= max(y, 1) or o >= max(b, 1) or g >= max(r, 1):
        print_dot()
        return "IMPOSSIBLE"
    
    sol = solve_small(r-g, y-v, b-o)
    
    if sol is None:
        print_dot()
        return "IMPOSSIBLE"
    
    if g >= 1:
        sol = sol.replace("R", "RG" * g + "R", 1)
    if v >= 1:
        sol = sol.replace("Y", "YV" * v + "Y", 1)
    if o >= 1:
        sol = sol.replace("B", "BO" * o + "B", 1)
    
    res = sol
    
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


