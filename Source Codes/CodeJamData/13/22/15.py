from __future__ import division
import pdb
import sys
import re
import time
from collections import namedtuple, Counter
from itertools import *
from copy import copy, deepcopy
from pprint import pprint
from glob import glob

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

def diamonds_in_layer(n):
    return 2 * (n + 1) * n + n + 1

def make_distribution(length, diamonds):
    current_d = Counter()
    current_d[(0, 0)] = 1
    for _ in xrange(diamonds):
        new_d = Counter()
        for (l, r), cnt in current_d.iteritems():
            if l < length and r < length:
                new_d[(l + 1, r)] += cnt
                new_d[(l, r + 1)] += cnt
            elif r < length:
                new_d[(l, r + 1)] += 2 * cnt
            else:
                assert l <= length # an important trick!
                new_d[(l + 1, r)] += 2 * cnt
        current_d = new_d
    return current_d

#print make_distribution(750, 2 * 750 + 1)
#
#for diamonds in xrange(7):
#    print diamonds, make_distribution(2, diamonds)
#
#sys.exit()

def solvecase():
    total_diamonds, target_x, target_y = readintlist()
    distance = (abs(target_x) + target_y) / 2
    if distance == 0: return 1.0
    base_diamonds = diamonds_in_layer(distance - 1)
    if total_diamonds <= base_diamonds: return 0.0
    if total_diamonds >= diamonds_in_layer(distance): return 1.0
    distribution = make_distribution(2 * distance, total_diamonds - base_diamonds)
#    pprint(distribution)
    total, good = 0, 0
    for (l, _), cnt in distribution.iteritems():
        total += cnt
        if l > target_y: good += cnt
    return '{:0.6f}'.format(good / total)

def solve(input_name, output_name):
    global input
    tstart = time.clock()
    input = open(input_name, 'r')
    output = open(output_name, 'w')
    casecount = readint()
    
    for case in range(1, casecount + 1):
        s = solvecase()
        s = "Case #%d: %s" % (case, str(s)) 
        print >>output, s
        print s 
        
    input.close()
    output.close()
    print '%s solved in %.3f' % (input_name, time.clock() - tstart)

def main():
    input_names = glob(taskname + '-*.in')
    assert len(input_names)
    input_names.sort(reverse = True)
    for input_name in input_names:
        solve(input_name, input_name.replace('.in', '.out')) 
                
if __name__ == '__main__':
    main()
