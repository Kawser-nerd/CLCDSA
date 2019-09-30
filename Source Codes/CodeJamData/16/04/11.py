#!/usr/bin/env python

import collections

import math
import re
import sys


INPUT = "tiny"
INPUT = "D-small-attempt0.in"
INPUT = "D-large.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

def iterate(rng, K):
    v = 0
    for i in rng:
        v *= K
        v += i
    return v

def do_trial(K, C, S):
    if S * C < K:
        return "IMPOSSIBLE"

    r = []
    checked_max = 0
    while checked_max < K:
        rng = list(range(checked_max, min(checked_max + C, K)))
        rng = ([0] * (C - len(rng))) + rng
        v = iterate(rng, K)
        checked_max += C
        r.append(v + 1)
    return ' '.join(str(x) for x in r)

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    K, C, S = [int(x) for x in f.readline().split()]
    v = do_trial(K, C, S)
    print "Case #%d: %s" % (i+1, v)
