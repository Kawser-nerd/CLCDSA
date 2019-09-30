def f2(C,D,V,seq):
    p = [False] * (V + 1)
    p[0] = True
    for i in xrange(C):
        for j in seq:
            for k in xrange(V, j - 1, -1):
                p[k] = p[k] or p[k - j]
    score = 0
    for m in xrange(V + 1):
        if not p[m]:
            score += 1
            for i in xrange(C):
                for k in xrange(V, m - 1, -1):
                    p[k] = p[k] or p[k - m]
    return score

def f(C,D,V,seq):
    seq = sorted(list(seq))
    canreach = 0
    score = 0
    for i in seq:
        while i > canreach + 1:
            score += 1
            canreach += C * (canreach + 1)
        canreach += C * i
    while V > canreach:
        score += 1
        canreach += C * (canreach + 1)
    return score

from sys import stdin

for case in xrange(1, 1 + int(stdin.readline())):
    (C, D, V) = tuple(int(z) for z in stdin.readline().split())
    seq = tuple(int(z) for z in stdin.readline().split())
    print "Case #%d: %d" % (case, f(C, D, V, seq))
