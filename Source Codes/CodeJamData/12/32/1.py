from sys import stdin
from math import sqrt

for cn in xrange(1,1+int(stdin.readline())):
    [D,N,A] = stdin.readline().split()
    D = float(D)
    [N,A] = [int(z) for z in [N,A]]
    dists = [[float(k) for k in stdin.readline().split()] for i in xrange(N)]
    accs = [float(k) for k in stdin.readline().split()]
    print "Case #%d:" % cn

    for i in xrange(1,N):
        if dists[i][1] >= D:
            [t0,d0] = dists[i-1]
            [t1,d1] = dists[i]
            T = t0 + ((D - d0) * (t1 - t0)) / (d1 - d0)
    for acc in accs:
        mustWait = 0.0
        for i in xrange(N - 1):
            [t0,d0] = dists[i]
            [t1,d1] = dists[i+1]
            dt = t1 - t0
            dd = d1 - d0
            if d0 > D:
                break
            mustWait = max(mustWait, t0 - sqrt(2 * d0 / acc))
            if d1 < D:
                mustWait = max(mustWait, t1 - sqrt(2 * d1 / acc))
            else:
                teps = (D - d0) * (t1 - t0) / (d1 - d0)
                mustWait = max(mustWait, teps + t0 - sqrt(2 * D / acc))
        print mustWait + sqrt(2 * D / acc)

