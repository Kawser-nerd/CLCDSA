#!/usr/bin/python

def lpos(N, L):
    return 2**N-2**(N-L)

def wpos(N, W):
    return 2**(N-W)-1

def hforl(N, L):
    r = 0
    for i in xrange(L):
        r = 2*r+2
    return min(2**N-1, r)

def hforw(N, W):
    r = 0
    for i in xrange(W):
        r = 2*r+1
    return max(0, 2**N-r-1)

def solve(N, P):
    maxl = 0
    while maxl <= N and lpos(N, maxl) < P: maxl += 1
    maxl -= 1
    guaranteed = hforl(N, maxl)

    minw = N
    while minw >= 0 and wpos(N, minw) < P: minw -= 1
    minw += 1
    could = hforw(N, minw)

    return (guaranteed, could)

T = input()

for t in xrange(T):
    N, P = map(int, raw_input().split())
    s=solve(N, P)
    print 'Case #%s: %s %s' % (t+1, s[0], s[1])
