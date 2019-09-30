#coding: 1251
#####################################################

from __future__ import division

import os
import sys
import operator
import string
import re
import time

from os.path import splitext
from copy import copy

from math import *
from operator import *
from collections import *
from itertools import *
from functools import *
from random import *

#####################################################

try:
    from do import report_working_on
except ImportError:
    report_working_on = lambda a,b: None

if len(sys.argv) > 1:
    fin = file(sys.argv[1], 'r')
    fout = file(splitext(sys.argv[1])[0]+'.out', 'w+')
else:
    fin = sys.stdin
    fout = sys.stdout

def dorun():
    cases = int(fin.next())
    for case in xrange(cases):
        report_working_on(case, cases)
        print>>fout, 'Case #%d: %s' % ( 1+case, solve(fin) )
    else:
        report_working_on(0,0)

#####################################################

def solve(fin):
    N, W, L = map(int, fin.next().split())
    rx = map(int, fin.next().split())
    rx0 = rx[:]

    rx.sort(key=lambda x:-x)
    MAP = []

    poss = [ (0,0), (W,L) ]
    for r, p  in zip(rx, poss):
        MAP += [ (r, p) ]
    del rx[0:len(MAP)]

    def isok(r, xy):
        x,y = xy
        if not 0 <= x <= W or not 0 <= y <= L: return False
        if any(  (x-xi)**2 + (y-yi)**2 < (ri + r)**2 for ri,(xi,yi) in MAP ): 
            return False
        return True

    d = 0.001
    while rx:
        r = rx[0]; del rx[0]

        for _ in xrange(100):
            ri,(xi,yi) = choice(MAP)
            a = uniform(0, 2*pi)
            x,y = xi+(ri+r+d)*sin(a), yi+(ri+r+d)*cos(a)
            
            if isok(r, (x,y)):
                MAP += [ (r, (x,y)) ]
                break
        else:
            rx += [r]

            if len(MAP) > 2:            
                t =  choice(MAP)
                MAP.remove(t)

                r1,(x,y) =t
                rx += [r1]

    out = []
    for r0 in rx0:
        for i,(r,xy) in enumerate(MAP):
            if r0 == r:
                del MAP[i]
                out += ['%f %1f' % xy]
                break

    return ' '.join(out)
    

      
#####################################################

if __name__=='__main__': dorun()
