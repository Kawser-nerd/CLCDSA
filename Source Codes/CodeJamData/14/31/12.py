#!/usr/bin/pypy

def gcd(a,b):
    while a:
        a,b = b%a,a
    return b

def solve():
    P, Q = map(int,raw_input().split('/'))
    g = gcd(P,Q)
    P/=g
    Q/=g
    cnt = 2**40
    if cnt % Q != 0:
        print "impossible"
        return
    for i in range(1,100):
        if P*2**i >= Q:
            print i
            return

T = int(raw_input())
for t in range(1,T+1):
    print "Case #%d:"%t,
    solve()
