#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def getline():
    return sys.stdin.readline().rstrip('\n')

def solve(a, b, k):
    count = 0
    for i in range(a):
        for j in range(b):
            if (i & j) < k:
                count += 1
    return count

ncases = int(getline())

for casenr in range(1, ncases+1):
    a, b, k = [ int(s) for s in getline().split() ]
    emit("Case #%d: %s\n", casenr, solve(a, b, k))
