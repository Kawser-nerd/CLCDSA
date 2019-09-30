import pdb
import sys
import re
import time
from collections import namedtuple
from itertools import *
from copy import copy, deepcopy
from heapq import heappop, heappush

taskname = 'B'
input = None

def readstr():
    return next(input).strip()

def readintlist():
    lst = map(int, readstr().split())
    return lst

def readint():
    lst = readintlist()
    assert len(lst) == 1
    return lst[0]

def solvecase():
    height, n, m = readintlist()
    ceiling = [readintlist() for _ in xrange(n)]    
    floor = [readintlist() for _ in xrange(n)]
    front = [(0.0, 0, 0)]
    visited = [[None for _ in xrange(m)] for _ in xrange(n)]
    
    def make_move(t, x, y, x1, y1):
        if (floor[x][y] + 50 > ceiling[x1][y1] or
            floor[x1][y1] + 50 > ceiling[x][y] or
            floor[x1][y1] + 50 > ceiling[x1][y1]):
            return None
        
        if height + 50 > ceiling[x1][y1]:
            # wait then move
            delay = (height + 50 - ceiling[x1][y1]) / 10.0
            height_after_delay = ceiling[x1][y1] - 50
            if height_after_delay >= floor[x][y] + 20:
                delay += 1.0
            else:
                delay += 10.0
            return (t + delay, x1, y1)
        
        if t == 0.0:
            # phase1 - move instantly
            return (t, x1, y1)
        # move immediately
        if height >= floor[x][y] + 20:
            delay = 1.0
        else:
            delay = 10.0
        return (t + delay, x1, y1)
    
    deltas = [(1, 0), (0, 1), (-1, 0), (0, -1)]
    current_t = 0.0
    while front:
        t, x, y = heappop(front)
        height -= (t - current_t) * 10.0
        current_t = t
        
        if visited[x][y] is not None and visited[x][y] <= t:
            continue
        visited[x][y] = t
        for dx, dy in deltas:
            x1 = x + dx
            y1 = y + dy
            if not (0 <= x1 < n and 0 <= y1 < m):
                continue 
            move = make_move(t, x, y, x1, y1)
            if move:
                heappush(front, move)
    # run the wave to the end, because what if we reach the front incorrectly?
    return visited[n - 1][m - 1]

def solve(suffix):
    global input
    tstart = time.clock()
    input = open(taskname + '-' + suffix + '.in', 'r')
    output = open(taskname + '-' + suffix + '.out', 'w')
    casecount = readint()
    
    for case in range(1, casecount + 1):
        s = solvecase()
        s = "Case #%d: %s" % (case, str(s)) 
        print >>output, s
        print s 
        
    input.close()
    output.close()
    print '%s solved in %.3f' % (suffix, time.clock() - tstart)
            
if __name__ == '__main__':
    solve('small')
    solve('large')
