# -*- coding: utf-8 -*-
"""
Created on Fri Apr 11 17:15:57 2014, uses python 3.4

@author: Eric
"""

from collections import *
from sys import argv, stdin, stdout, stderr
    
Case = namedtuple('Case', 'naomi, ken')

def readcase(f):
    blocks = int(next(f))
    naomi = sorted(readfloats(f))
    ken = sorted(readfloats(f))
    assert blocks == len(ken) == len(naomi)
    return Case(naomi, ken)

def solvecase(case):
    naomi, ken = case
    return '%d %d' % (liewar(ken=ken, naomi=naomi), war(ken=ken, naomi=naomi))

def war(ken, naomi):
    kenwins = 0
    kencursor = 0
    for nweight in naomi:
        while kencursor < len(ken):
            if ken[kencursor] > nweight:
                kenwins += 1
                kencursor += 1
                break
            else:
                kencursor += 1
        else:
            break
    return len(ken) - kenwins
    
def liewar(ken, naomi):
    return len(ken) - war(naomi, ken)

def readfloats(f):
    return list(map(float, next(f).split(' ')))

def main():
    with open(argv[1]) as f, open(argv[2], 'w') as out:
        cases = int(next(f))
        for case in range(1, cases+1):
            print('Case #%d: %s' % (case, solvecase(readcase(f))), file=out)

main()
