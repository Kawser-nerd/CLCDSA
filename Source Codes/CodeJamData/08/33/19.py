#!/usr/bin/python

import os
import sys

#sys.stdin = open('C-test.in', 'r')
#sys.stdout = open('C-test.out', 'w')
#sys.stdin = open('C-small.in', 'r')
#sys.stdout = open('C-small.out', 'w')
sys.stdin = open('C-small-attempt0.in', 'r')
sys.stdout = open('C-small-attempt0.out', 'w')
#sys.stdin = open('C-small-attempt1.in', 'r')
#sys.stdout = open('C-small-attempt1.out', 'w')
#sys.stdin = open('C-large.in', 'r')
#sys.stdout = open('C-large.out', 'w')

DEBUG = 1 or os.getenv("DEBUG") == '1'

if DEBUG:
    sys.stderr = open('log', 'w')

def debug(*what):
    if DEBUG:
        sys.stderr.write("[DEBUG] " + " ".join(map(str, what)) + "\n")

#-----------------------------------------------------------------------------
L = 1000000007


for case in xrange(input()):
    debug()
    debug("Case #%d:" % (case + 1))
    n, m, X, Y, Z = map(int, raw_input().split())
    A = []
    for i in xrange(m):
        A.append(input())
    debug('n m X Y Z', n, m, X, Y, Z, 'A', A)
    S = []
    for i in xrange(n):
        S.append(A[i % m])
        A[i % m] = (X * A[i % m] + Y * (i + 1)) % Z
    debug('S', S)

    c = [1] * n
    r = 0
    for i in xrange(n):
        debug('i', i)
        for j in xrange(i):
            if S[j] < S[i]:
                c[i] += c[j]; c[i] %= L
        r += c[i]; r %= L
        debug('c', c)
        debug('r', r)
            
    print "Case #%d: %d" % (case + 1, r)
