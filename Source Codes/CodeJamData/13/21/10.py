#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def solve(moteA, motes):
    while motes and moteA > motes[0]:
        moteA += motes[0]
        del motes[0]
    solve_by_del = len(motes)
    if moteA == 1 or solve_by_del <= 1:
        return solve_by_del
    solve_by_add = 1 + solve(moteA + moteA - 1, motes)
    return min(solve_by_del, solve_by_add)

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

for casenr in range(1, ncases+1):
    moteA, nmotes = [ int(s) for s in getline().split() ]
    motes = [ int(s) for s in getline().split() ]
    motes.sort()
    emit("Case #%d: %s\n", casenr, solve(moteA, motes))
