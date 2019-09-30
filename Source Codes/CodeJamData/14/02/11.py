# -*- coding: utf-8 -*-
"""
Problem B. Cookie Clicker Alpha
uses python 3.4

@author: Eric Kuritzky
"""

from collections import *
from sys import argv, stdin, stdout, stderr
    
Case = namedtuple('Case', 'C,F,X')

def readcase(f):
    return Case(*readfloats(f))

def solvecase(case):
    it = farmcost(*case)
    best = next(it)
    farms = 0
    for time in it:
#        print('time=%f, best=%f' % (time, best))
        if time < best:
            best = time
            farms += 1
        else:
#            print('%d farms!' % farms, file=stderr)
            return best
            
def farmcost(c, f, x):
#    print(c, f, x, file=stderr)
    rate, spent = 2, 0
    while True:
#        print(spent, rate, file=stderr)
        yield spent + x / rate
        spent += c / rate
        rate += f

def readfloats(f):
    return list(map(float, next(f).split(' ')))

def main():
    with open(argv[1]) as f, open(argv[2], 'w') as out:
        cases = int(next(f))
        for case in range(1, cases+1):
            print('Case #%d: %.7f' % (case, solvecase(readcase(f))), file=out)

main()
