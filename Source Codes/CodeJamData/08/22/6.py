from sys import stdin
from collections import deque

MAX = 1000000

primes = set(xrange(2,MAX),)
for p in xrange(2, MAX):
    if p in primes:
        for i in xrange(2*p, MAX, p):
            if i in primes:
                primes.remove(i)

tno = int(stdin.readline())
for j in xrange(tno):
    A, B, P = map(long, stdin.readline().strip().split())
    tab = [-1]*(B-A+1)
    pr = [x for x in primes if x >= P and x <= B-A]
    hm = 0
    ed = [[] for _ in xrange(0, B-A+1)]
    for p in pr:
        f = ((A+p-1)//p)*p - A
        for x in xrange(f, B-A+1, p):
            if x != f:
                ed[x-p].append(x)
                ed[x].append(x-p)
    for i in xrange(B-A+1):
        if tab[i] != -1:
            continue
        q = deque((i,))
        tab[i] = -1
        while q:
            x = q.popleft()
            for e in ed[x]:
                if tab[e] == -1:
                    tab[e] = i
                    q.append(e)
        hm += 1
        del q
    del pr
    del ed
    
    print "Case #%d: %d"%(j+1, hm,)
