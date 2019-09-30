import pdb
import sys
import re
import time
from collections import namedtuple
from itertools import *
from copy import copy, deepcopy
from pprint import pprint
from glob import glob

taskname = 'A'
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
    current_size, n = readintlist()
    motes = readintlist()
    assert len(motes) == n
    
    if current_size <= 1:
        return len(motes)
    
    best = [None]
    def check_best(value):
        old_best = best[0]
        if old_best is None or value < old_best:
            best[0] = value
    
    
            
    motes.sort()
    actions = 0
    for n, mote in enumerate(motes):
        check_best(actions + len(motes) - n)
        while mote >= current_size:
            current_size += current_size - 1
            actions += 1
        current_size += mote
    check_best(actions)
    return best[0]

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
