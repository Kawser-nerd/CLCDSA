from sys import stdin, stderr

def getInt():
    return int(stdin.readline())

def getInts():
    return tuple(int(z) for z in stdin.readline().split())

def getWords():
    return set(stdin.readline().split())

def bitcount(n):
    k = 0
    while n:
        n -= (n & (-n))
        k += 1
    return k

from pulp import *

numCases = getInt()
for case in xrange(1, 1+numCases):
    N = getInt()
    sents = [getWords() for k in xrange(N)]
    allwords = sorted(list(set([v for s in sents for v in s])))
    wlookup = {allwords[i]:i for i in xrange(len(allwords))}
    Nw = len(allwords)
    esen = [LpVariable("es%d" % i,0,1,'Integer') for i in xrange(N)]
    ewor = [LpVariable("ew%d" % i,0) for i in xrange(Nw)]
    fwor = [LpVariable("fw%d" % i,0) for i in xrange(Nw)]
    bwor = [LpVariable("bw%d" % i,0) for i in xrange(Nw)]
    prob = LpProblem("problem", LpMinimize)
    prob += esen[0] == 1
    prob += esen[1] == 0
    for i in xrange(N):
        for word in sents[i]:
            wind = wlookup[word]
            prob += esen[i] <= ewor[wind]
            prob += (1 - esen[i]) <= fwor[wind]
    for wind in xrange(Nw):
        prob += ewor[wind] + fwor[wind] <= 1 + bwor[wind]
    prob += sum(bwor)
    prob.solve()
    rec = value(sum(bwor))
    print "Case #%d: %d" % (case, rec)
    print >>stderr, "Case #%d: %d" % (case, rec)
