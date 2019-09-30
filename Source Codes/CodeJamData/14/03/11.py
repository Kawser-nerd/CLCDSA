# -*- coding: utf-8 -*-
"""
Problem C. Minesweeper Master
uses python 3.4

@author: Eric
"""

from collections import *
from sys import argv, stdin, stdout, stderr
    
Case = namedtuple('Case', 'r,c,m')

def readcase(f):
    return Case(*readints(f))

def solvecase(case):
    r, c, m = case
    if r <= c:
        ans = solve(r, c, m)
    else:
        ans = solve(c, r, m)
        if ans:
            ans = map(''.join, zip(*ans))
    return ans if ans else ['Impossible']

def solve(r, c, m):
    assert r <= c and m < r*c
    holes = r*c - m
    if r == 1:
        return formboard(r, c, [holes])
    elif holes == 1:
        return formboard(r, c, [1])
    elif r == 2:
        return holes > 2 and (holes % 2 == 0) and formboard(r, c, [holes//2] * 2)
    elif holes in (4, 6):
        return formboard(r, c, [holes//2] * 2)
    elif holes < 8:
        return None
    else: # holes >= 8
        blankrows = min(r, holes//2)
        longrows = holes % blankrows
        shortlen = holes // blankrows
        blanklist = [shortlen + 1] * longrows + [shortlen] * (blankrows - longrows)
        if longrows == 1:
            if shortlen > 2:
                blanklist[1] += 1
                blanklist[-1] -= 1
            else:
                assert blankrows > 3
                blanklist.pop()
                blanklist[1:3] = [shortlen + 1] * 2
        assert sum(blanklist) == holes
        return formboard(r, c, blanklist)
        
def formboard(r, c, blanklist):
    board = [['*'] * c for _ in range(r)] 
    for i, j in enumerate(blanklist):
        board[i][:j] = ['.']*j
    board[0][0] = 'c'
    return map(''.join, board)
        
def readints(f):
    return list(map(int, next(f).split(' ')))

def main():
    with open(argv[1]) as f, open(argv[2], 'w') as out:
        cases = int(next(f))
        for case in range(1, cases+1):
            print('Case #%d:' % (case), file=out)
            for line in solvecase(readcase(f)):
                print(line, file=out)

main()
