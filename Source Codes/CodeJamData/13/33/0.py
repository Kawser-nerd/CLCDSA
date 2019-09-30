#! /usr/bin/env python

from sys import stdin
import numpy as np

ntest = input()

for test in xrange(ntest):
    N = input()
    attacks = []
    for i in xrange(N):
        d, n, w, e, s, delta_d, delta_p, delta_s = [int(i) for i in stdin.readline().strip().split(' ')]
        for j in xrange(n):
            attacks.append((d, w, e, s))
            d += delta_d
            w += delta_p
            e += delta_p
            s += delta_s
    attacks.sort()
    new_wall = np.zeros(500, dtype=int)
    wall = np.zeros(500, dtype=int)
    day = 0
    result = 0
    for d, w, e, s in attacks:
        if d > day: # new day
            wall = new_wall.copy()
            day = d
        if wall[w+250:e+250].min() < s: # succesful attack
            result += 1
            new_wall[w+250:e+250] = np.maximum(new_wall[w+250:e+250], s)
    print "Case #{}: {}".format(test+1, result)
