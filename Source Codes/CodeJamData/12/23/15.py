#!/usr/bin/python

import sys

from itertools import *

def allThe(S):
    yield set(), set(), S
    for s in S:
        SS = S - set([s])
        for A, B, rem in allThe(SS):
            yield A | set([s]), B, rem
            yield A, B | set([s]), rem

def formatted(A, B):
    return '\n' + ' '.join(map(str, A)) + '\n' + ' '.join(map(str, B))

def solve(S):
    '''
        for A, B, SS in allThe(S):
            if not A and not B:
                continue
            sa = sum(A)
            sb = sum(B)
            if sa == sb:
                return formatted(A, B)
            if sa - sb in SS:
                return formatted(A, B | set([sa - sb]))
            if sb - sa in SS:
                return formatted(A | set([sb - sa]), B)

        return '\nImpossible'
    '''

    allSums = {}
    for i in range(1, len(S)):
        for SS in combinations(S, i):
            ss = sum(SS)
            if ss in allSums:
                return formatted(list(SS), allSums[ss])
            allSums[ss] = list(SS)

    return '\nImpossible'

T = int(raw_input())
for i in range(T):
    s = set(int(s) for s in raw_input().split(' ')[1:])
    print "Case #%i: %s" % (i+1, solve(s))
    sys.stdout.flush()

