#!/usr/bin/python

import sys
NN = 100003

cache = {}

def bin(n, k):
    if (n < k): return 0
    if (k < 0): return 0
    if (n, k) in cache: return cache[(n, k)]
    s = 1;
    for i in xrange(k+1, n+1):
        s *= i
    for i in xrange(1, n-k+1):
        s /= i
    s = s % NN
    cache[(n, k)] = s
    return s

def calcola(N, n, k):
    if (k in [1, 2]) : return 1;
    if (k == 3): return n-3
    if (N[n][k] != -1): return N[n][k]
    s = 0
    for t in xrange(1, k):
        s = (s + bin(n-k-1, k-t-1) * calcola(N, k, t)) % NN
    N[n][k] = s % NN
    return s


C = int(sys.stdin.readline())
for c in xrange(C):
    n = int(sys.stdin.readline())
    N = []
    for i in xrange(n+1):
        N.append([-1] * (n))
    s = 1
    for i in xrange(2, n):
        s = (s + calcola(N, n, i)) % NN
    print "Case #%d: %d" % (c+1, s)
