#!/usr/bin/python

import sys

def emit(text, *args):
    msg = text % args
    sys.stderr.write(msg)
    sys.stdout.write(msg)

def choose(n, k):
    if 0 <= k <= n:
        ntok = 1
        ktok = 1
        for t in xrange(1, min(k, n - k) + 1):
            ntok *= n
            ktok *= t
            n -= 1
        return ntok // ktok
    else:
        return 0

def pyramid_size(height):
    base = 2 * height + 1
    return (base * (base + 1)) / 2

def solve(n, x, y):
    if x == 0:
        if n >= pyramid_size(y/2):
            return 1.0
        else:
            return 0.0
    if x < 0:
        x = -x  # problem is symmetrical around y
    foundation_height = (y + x)/2 - 1
    foundation = pyramid_size(foundation_height)
    n = n - foundation
    if n <= y:
        return 0.0
    if n > (foundation_height + 1) * 2 + y:
        return 1.0
    # Now what is the chance of getting at least y+1 wins in n tries?
    options = 0
    for i in range(y+1, n+1):
        options += choose(n, i)
    # divide options by 2 ** n, but carefully to not lose precision
    for i in range(n):
        if options > 2**30:
            options = options // 2
        else:
            options = options / 2.0
    return options

def getline():
    return sys.stdin.readline().rstrip('\n')

ncases = int(getline())

for casenr in range(1, ncases+1):
    n, x, y = [ int(s) for s in getline().split() ]
    emit("Case #%d: %s\n", casenr, solve(n, x, y))
