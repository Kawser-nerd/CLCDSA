# -*- coding: utf-8 -*-
import sys
fin = sys.stdin
T = int(fin.readline())

DELTA = 0.000000001

for case in range(1,T+1):
    line = map(int, fin.readline().split())
    N = line[0]
    points = line[1:]
    total = sum(points)
    pointfs = []
    for p in points:
        pointfs.append(p * 1.0 / total)

    #sorted = points[:]
    #sorted.sort()
    result = []
    for i, p in enumerate(pointfs):
        a = 0.0
        b = 1.0
        guess = 0.5
        while b - a > DELTA:
            guess = (b+a)/2
            target = p + guess
            remainder = 1.0 - guess
            for j, q in enumerate(pointfs):
                if i == j:
                    continue
                required = target - q
                if required > 0:
                    remainder -= required
            if remainder > 0:
                # can be eliminated
                a = guess
            else:
                b = guess
        result.append(guess)


    print "Case #%d: %s" % (case, ' '.join(["%.6f" % (s*100) for s in result]))


