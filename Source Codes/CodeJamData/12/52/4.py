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
    S,M = map(int, fin.next().split())
    Mx = [ tuple(map(int, x.split())) for x in islice(fin, M) ]

    neighbours = [ (0,-1), (0,1),
                   (1,0), (-1,0),
                   (1,1), (-1,-1) ]

    maxim = S-1

    def stillOnBoard(x, y):
        if x<1 or y <1: return False
        if x>2*S-1 or y>2*S-1: return False
        if fabs(x-y) > S-1: return False
        return True        

    corners = [ (1,1), (1,S), (S,1), (2*S-1,S), (S, 2*S-1), (2*S-1, 2*S-1) ]
    def atEdge(cc):
        x,y = cc
        if x == 1: return 1
        elif y == 1: return 2
        elif x == 2*S-1: return 3
        elif y == 2*S-1: return 4
        elif y-x == S-1: return 5
        elif x-y == S-1: return 6
        return 0

    def isCorner(cc):
        if cc in corners:
            return corners.index(cc) + 1
        return 0

    board = {}
    boardEdges = {}
    boardCorners = {}
    bingo = []

    for i, cc in enumerate(Mx):
        board[cc] = 1
        c = isCorner(cc)
        e = atEdge(cc)

        if c: 
            boardCorners.setdefault(cc, set()).add(c)
            e = False
        
        if e: 
            boardEdges.setdefault(cc, set()).add(e)
            
        scan = set([cc])

        while scan:
            x,y = scan.pop()
            e = boardEdges.get((x,y), set())
            c = boardCorners.get((x,y), set())
            for dx,dy in neighbours:
                x1,y1 = x+dx, y+dy
                if stillOnBoard(x1, y1) and (x1,y1) in board:

                    c1 = boardCorners.get((x1, y1), set())
                    if  c1 != c:
                        scan.add((x1,y1))
                        
                        c1.update( c )
                        boardCorners[(x1,y1)] = c1
                        if len(c1)>=2: bingo += ['bridge']
                    
                    e1 = boardEdges.get((x1, y1), set())
                    if e1 != e: 
                        scan.add((x1,y1)) 

                        e1.update( e )
                        boardEdges[(x1,y1)] = e1
                        if len(e1)>=3: bingo += ['fork']

        # поиск всей группы
        wasin = set()
        scan.add(cc)
        while scan:
            x,y = scan.pop()
            wasin.add((x,y))
            for dx,dy in neighbours:
                x1,y1 = x+dx, y+dy
                if stillOnBoard(x1, y1) and (x1,y1) in board and (x1,y1) not in wasin:
                    scan.add((x1,y1))

        # wasin содержит всю группу

        # создание рядов по координате x
        xx = {}
        for x,y in wasin:
            xx.setdefault(x, list()).append( y )
                
        # поиск зазоров
        zeros = set()
        for x,row in xx.iteritems():
            row.sort()
            while len(row) >= 2:
                if row[0]+1 != row[1]:
                    zeros.add((x,row[0]+1))
                row.pop(0)

        free = set()
        for x,y in zeros:

            scan = set()
            wasin = set()

            scan.add((x,y))

            while scan:
                x,y = scan.pop()
                wasin.add((x,y))

                if atEdge((x,y)) or isCorner((x,y)) or (x,y) in free:
                    free.update( wasin )
                    wasin.clear()
                    break
    
                for dx,dy in neighbours:
                    x1,y1 = x+dx, y+dy
    
                    if stillOnBoard(x1, y1) and   (x1,y1) not in board   and (x1,y1) not in wasin:
                        scan.add((x1,y1))
                
            if wasin:
                bingo += ['ring']

        if bingo:
            bingo = sorted(set(bingo))
            return '-'.join(bingo) +' in move %s' % (i+1)

    return 'none'
                  
#####################################################

if __name__=='__main__': dorun()
