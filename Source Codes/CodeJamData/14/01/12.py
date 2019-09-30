# -*- coding: utf-8 -*-
"""
Problem A. Magic Trick
uses python 3.4

@author: Eric Kuritzky
"""
from collections import *
from sys import argv, stdin, stdout, stderr
    
Case = namedtuple('Case', 'selection, array')

def readcase(f):
    selection = [int(next(f))]
    array = [[readints(f) for _ in range(4)]]
    selection.append(int(next(f)))
    array.append([readints(f) for _ in range(4)])
    return Case(selection, array)

def solvecase(case):
#    selection, array = case
    sets = [set(arr[sel - 1]) for sel, arr in zip(*case)]
    possible = sets[0] & sets[1]
    if not possible:
        return "Volunteer cheated!"
    elif len(possible) > 1:
        return 'Bad magician!'
    else:
        return str(possible.pop())
        
def readints(f):
    return list(map(int, next(f).split(' ')))

def main():
    with open(argv[1]) as f, open(argv[2], 'w') as out:
        cases = int(next(f))
        for case in range(1, cases+1):
            print('Case #%d: %s' % (case, solvecase(readcase(f))), file=out)

main()
