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
    n, q = [int(u) for u in sys.stdin.readline().split()]
    horses = [[int(u) for u in sys.stdin.readline().split()] for i in xrange(n)]
    routes = [[int(u) for u in sys.stdin.readline().split()] for i in xrange(n)]
    wanted = [[int(u)-1 for u in sys.stdin.readline().split()] for i in xrange(q)]
    
    return n, q, horses, routes, wanted


def write(res):
    # write answer for a single test case
    for t in res:
        print t,
    print


def solve(data):
    n, q, horses, routes, wanted = data
    
    sol = []
    
    for u, v in wanted:
        queue = Queue.PriorityQueue()
        queue.put((0.0, u, u, 0))
        
        visited = [False for i in xrange(n)]
        
        visited_from = [[False for i in xrange(n)] for j in xrange(n)]
        
        while not queue.empty():
            t, x, c, s = queue.get()
            
            if visited_from[x][c]:
                # already visited
                continue
            
            # print "visiting", t, x, c, s
            
            for i in xrange(n):
                # visit neighbours
                
                d = routes[x][i]
                
                if d < 0:
                    # no route
                    continue
                
                # with the same horse c
                if s + d <= horses[c][0]:
                    queue.put((t + float(d) / horses[c][1], i, c, s + d))
                
                # with the new horse x
                if not visited[x] and d <= horses[x][0] and x != c:
                    queue.put((t + float(d) / horses[x][1], i, x, d))
            
            visited[x] = True
            visited_from[x][c] = True
            
            if x == v:
                # reached destination
                sol.append(t)
                break
    
    
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


