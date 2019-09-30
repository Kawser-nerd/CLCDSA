#!/usr/bin/env python

memo_fact = {0:1, 1:1, 2:2}
def fact(x):
    assert x >= 0
    if x in memo_fact: return memo_fact[x]
    res = fact(x-2)*x*(x-1)
    memo_fact[x] = res
    return res

def choose(amt, fro):
    assert 0 <= amt <= fro
    return fact(fro)*1.0/fact(amt)/fact(fro-amt)

def calcprob(n, c, have):
    match = []

    max_match = min(n, have)
    p = [0] * (max_match+1)
    tot = choose(n, c)
    for m in range(max_match+1):
        if m > have: continue
        if n-m > c-have: continue
        # choosing m from the ones i have (have)
        # choosing n-m from the ones left (c-have)
        p[m] = choose(m,have)*choose(n-m, c-have)/tot
    return p

def fumble(n, c):
    round = 0
    phave = [1.0]+[0.0]*(c)

    cost    = 0     # cum cost
    probun  = 1.0   # unfinished

    while (round+1)*probun > 1e-8:
        round += 1
        next_phave = [0.0]*(c+1)
        for have,p in enumerate(phave):
            if p == 0.0: continue
            match_p = calcprob(n, c, have)
            start = max(0, have-(c-n))
            for i, mp in enumerate(match_p):
                if i < start: continue
                next_phave[have+n-i] += p*mp
        probun -= next_phave[c]
        cost += round * next_phave[c]
        phave = next_phave[:c]
    return cost
       
import sys
file = sys.stdin

cases = int(file.readline().strip())
for case in xrange(cases):
    c, n = map(int, file.readline().strip().split())
    print "Case #%d: %.7f" % (case+1, fumble(n, c))

