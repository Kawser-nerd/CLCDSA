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
from pulp import *

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
    r, c = [int(_) for _ in sys.stdin.readline().split()]
    house = [sys.stdin.readline().replace('\n','') for i in xrange(r)]
    
    return r, c, house


def write(res):
    # write answer for a single test case
    if res is None:
        print "IMPOSSIBLE"
    else:
        print "POSSIBLE"
        r, c, house = res
        for i in xrange(r):
            for j in xrange(c):
                sys.stdout.write(house[i, j])
            print


def find_trajectory(r, c, house, a_i, a_j, direction):
    L = 'L' # arrived from left
    R = 'R'
    U = 'U'
    D = 'D'
    
    visited = set() # visited cells with coming direction
    
    queue = []  # queue of elements (cell, direction L/R/U/D)
    
    if direction == '|':
        queue = [((a_i+1, a_j), U), ((a_i-1, a_j), D)]
    else:
        queue = [((a_i, a_j+1), L), ((a_i, a_j-1), R)]
    
    safe = True
    
    while len(queue) > 0:
        cell, d = queue.pop()
        i, j = cell
        
        if not (0 <= i < r and 0 <= j < c):
            # out of house
            continue
        
        if house[cell] == '#':
            # wall
            continue
        
        if house[cell] in ('-', '|'):
            # hit a shooter
            safe = False
            break
        
        if (cell, d) in visited:
            # already visited from this direction
            continue
        
        visited.add((cell, d))
        
        # find next cell
        next = None
        if house[cell] == '.':
            next = {
                L: ((i, j+1), L),
                R: ((i, j-1), R),
                U: ((i+1, j), U),
                D: ((i-1, j), D),
            }[d]
        elif house[cell] == '/':
            next = {
                L: ((i-1, j), D),
                R: ((i+1, j), U),
                U: ((i, j-1), R),
                D: ((i, j+1), L),
            }[d]
        elif house[cell] == '\\':
            next = {
                L: ((i+1, j), U),
                R: ((i-1, j), D),
                U: ((i, j+1), L),
                D: ((i, j-1), R),
            }[d]
        else:
            assert False
        
        queue.append(next)
    
    # print (a_i, a_j), direction
    # print visited, safe
    
    if not safe:
        return None
    
    else:
        return set(cell for cell, d in visited if house[cell] == '.')


def solve(data):
    r, c, house = data
    house = {(i, j): house[i][j] for i in xrange(r) for j in xrange(c)}
    
    shooters = []
    
    for ((i,j), x) in house.iteritems():
        if x in ('-', '|'):
            shooters.append((i, j))
    
    trajectories = {}
    
    # find trajectories
    for (i, j) in shooters:
        visited = {}
        for direction in ['|', '-']:
            v = find_trajectory(r, c, house, i, j, direction)
            if v is not None:
                visited[direction] = v
        trajectories[i, j] = visited
    
    # print trajectories
    
    if any(len(x) == 0 for x in trajectories.itervalues()):
        # something is not safe
        sys.stderr.write(".")
        sys.stderr.flush()
        return None
    
    # find empty space
    empty = set()
    for ((i,j), x) in house.iteritems():
        if x == '.':
            empty.add((i, j))
    
    for ((i, j), visited) in trajectories.iteritems():
        if len(visited) == 1:
            # no choice
            for (direction, v) in visited.iteritems():
                house[i, j] = direction
                # print "HERE", v, empty
                for cell in v:
                    if cell in empty:
                        # print "removing", cell
                        empty.remove(cell)
            
        else:
            assert len(visited) == 2
    
    # print empty
    
    prob = LpProblem("myProblem", LpMaximize)
    
    real_shooters = [(i, j) for ((i, j), visited) in trajectories.iteritems() if len(visited) == 2]
    
    variables = {(i, j, direction): LpVariable("%d,%d,%s" % (i, j, direction), lowBound=0, upBound=1, cat="Integer") for (i, j) in real_shooters for direction in ['|', '-']}
    
    # print empty
    # print variables
    
    for i, j in real_shooters:
        prob += variables[i,j,'|'] + variables[i,j,'-'] == 1
    
    for cell in empty:
        # must shoot it
        good_variables = []
        for i, j in real_shooters:
            for direction in ['|', '-']:
                if cell in trajectories[i,j][direction]:
                    # good choice
                    good_variables.append(variables[i,j,direction])
        # print cell, good_variables
        prob += lpSum(good_variables) >= 1
    
    prob.setObjective(lpSum([]))
    
    status = prob.solve()
    
    if LpStatus[status] != "Optimal":
        sys.stderr.write(".")
        sys.stderr.flush()
        return None
    
    # print "****"
    for (i, j) in real_shooters:
        x = None
        for direction in ['|', '-']:
            if value(variables[i,j,direction]) == 1:
                x = direction
        
        # print i, j, x
        house[i, j] = x
    
    # print house
    
    sys.stderr.write(".")
    sys.stderr.flush()
    return r, c, house


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


