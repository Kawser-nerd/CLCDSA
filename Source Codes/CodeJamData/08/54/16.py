#!/usr/bin/env python

import sys

readline = lambda : sys.stdin.readline()

C = int(readline())

rocks = set()
seen = {}
H, W = 0,0

def solve(pos):
    if pos[0] <= 0 or pos[1] <= 0:
        return 0
    if pos in rocks:
        return 0
    if pos in seen:
        return seen[pos]
    a = solve((pos[0] - 2, pos[1] - 1) ) + solve( (pos[0] - 1, pos[1] - 2))
    a %= 10007
    seen[pos] = a
    return a

for c in range(C):
    H, W, R = map(int, readline().split())

    rocks = set()
    seen = {(1,1) : 1}

    for r in range(R):
        a, b = map(int, readline().split())
        rocks.add((a, b))
        
    print "Case #%d: %d" % (c+1, solve((H, W)))
