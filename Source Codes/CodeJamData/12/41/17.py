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
    N = int(fin.next())
    DL = [map(int, fin.next().split()) for i in xrange(N)]
    END = int(fin.next())

    d,le = map(list, zip(*DL))

    Power = [-1] * N
    Power[0] = d[0]

    d += [END] # обозначаем конец
    le += [0]
    Power += [-1]

    for i in xrange(N+1):
        j = i+1
        di,li,Pi = d[i], le[i], Power[i]
        for j in xrange(i+1, N+1):
            dj, lj = d[j], le[j]
            if di + Pi < dj: break # долетает

            delta = dj - di
            Pn = min(lj, delta)
            if Power[j] < Pn:      # улучшает результат
                Power[j] = Pn

    if Power[-1] >=0: return 'YES'
    else:             return 'NO'
              
      

      
#####################################################

if __name__=='__main__': dorun()
