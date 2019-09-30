import fractions
import sys
import heapq
FF = fractions.Fraction

def _cc():
    for line in sys.stdin:
        for xx in line.strip().split():
            yield xx

_cin = _cc()
cin = _cin.next

def pp(s):
    a, b = s.split('.')
    a = int(a)
    b = int(b,10)
    return a*10000 + b

def do_case(cn):
    N = int(cin())
    K = int(cin())
    U = pp(cin())
    cores = [pp(cin()) for i in xrange(N)]
    print >>sys.stderr, cores
    cores.sort()
    while U > 0:
        lowthing = heapq.heappop(cores)
        nextthing = None
        for p in cores:
            if p > lowthing and (nextthing is None or p < nextthing):
                nexthing = p
        if nextthing is None:
            nextthing = lowthing+1
        touse = min(U, nextthing-lowthing)
        U -= touse
        lowthing += touse
        heapq.heappush(cores, lowthing)

    prob = 1.0
    for p in cores:
        prob *= (p / 10000.0)

    print "Case #%d: %.12lf" % (cn, prob)



CC = int(cin())
for cn in xrange(1, CC+1):
    do_case(cn)
