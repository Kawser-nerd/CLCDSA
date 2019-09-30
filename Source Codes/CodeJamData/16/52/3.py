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
    n = int(sys.stdin.readline())
    pre = [int(u) for u in sys.stdin.readline().split()]
    first = sys.stdin.readline().replace('\n','')
    m = int(sys.stdin.readline())
    cool = sys.stdin.readline().split()
    
    return n, pre, first, m, cool


def write(res):
    # write answer for a single test case
    for r in res:
        print r,
    print


def compute_num(x, children, num):
    if num[x] is not None:
        return num[x]
    
    # return (number of ways, descendants including x)
    if len(children[x]) == 0:
        res = 1, 1
    
    else:
        a = [compute_num(y, children, num) for y in children[x]]
        
        descendants = sum(d for w,d in a) + 1
        ways = math.factorial(descendants-1)
        for w,d in a:
            ways /= math.factorial(d)
            ways *= w
        
        res = ways, descendants
    
    num[x] = res
    return res


def multi(a):
    descendants = sum(d for w,d in a)
    ways = math.factorial(descendants)
    for w,d in a:
        ways /= math.factorial(d)
        ways *= w
    
    return ways



def weighted_choice(choices):
   # http://stackoverflow.com/questions/3679694/a-weighted-version-of-random-choice
   total = sum(w for c, w in choices)
   r = random.uniform(0, total)
   upto = 0
   for c, w in choices:
      if upto + w >= r:
         return c
      upto += w
   assert False, "Shouldn't get here"



def simul(n, children, num):
    open_nodes = [0]
    res = []
    
    while len(open_nodes) > 0:
        # print open_nodes
        ways = []
        for (i,x) in enumerate(open_nodes):
            a = [num[y] for y in open_nodes if y != x]
            a += [num[y] for y in children[x]]
            ways.append(multi(a))
        
        s = float(sum(ways))
        choices = [(i, float(w)/s) for (i,w) in enumerate(ways)]
        # print choices, children
        i = weighted_choice(choices)
        # print i
        res.append(open_nodes[i])
        
        for x in children[open_nodes[i]]:
            open_nodes.append(x)
        
        open_nodes.pop(i)
    
    return res


def solve(data):
    n, pre, first, m, cool = data
    
    children = [[] for i in xrange(n+1)]
    for (i,x) in enumerate(pre):
        children[x].append(i+1)
    
    num = [None for i in xrange(n+1)]
    
    for i in xrange(n+1):
        compute_num(i, children, num)
    
    # print children
    # print num
    
    rate = [0 for i in xrange(m)]
    
    N = 2000
    
    for k in xrange(N):
        seq = simul(n, children, num)
        string = ''.join([first[j-1] for j in seq[1:]])
        # print seq
        # print string
        
        for (i,c) in enumerate(cool):
            if c in string:
                rate[i] += 1
        
    # print rate
    
    res = [float(r)/float(N) for r in rate]
    
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


