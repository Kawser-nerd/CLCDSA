#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from sys import stderr, setrecursionlimit
from collections import deque
from itertools import *
import sys
from sys import stderr
from collections import deque, defaultdict
from itertools import *
from math import *
from bisect import *
data = deque(map(int,sys.stdin.read().split()))
token = data.popleft
T = int(token())

# Bisect_right
def bisect_right_fun(b, e, callback):
    if b == e:
        return e - 1

    m = int((b+e)/2)
    if callback(m):
        return bisect(m+1, e, callback)
    else:
        return bisect(b, m, callback)

def mainSmall():
    def test():
        E = token()
        R = token()
        N = token()
        v = [token() for _ in range(N)]
        res = 0

        rng = range(1,E+1)

        def test(sel):
            cur = 0
            e = E
            for i, j in enumerate(sel):
                if e < j:
                    return -1
                cur += j * v[i]
                e = min(E, e - j + R)
            return cur


        for sel in product(*([rng]*N)):
            res = max(res, test(sel))

        return res

    for case in xrange(1, T+1):
        print "Case #%d: %s" % (case, test())
        sys.stdout.flush()

def mainLarge():
    setrecursionlimit(100000)
    def test():
        E = token()
        R = token()
        N = token()
        v = [token() for _ in range(N)]
        res = 0

        rng = range(1,E+1)

        def max_pos(l):
            mv = max(l)
            return l.index(mv)

        def res_for(i, j, start, end):
            if i == j:
                return 0

            # N^2 crap :< - should make it
            peak = i + max_pos(v[i:j])
            # How long can we raise?
            raise_to = min(start + (peak-i)*R, E)
            # How long we have to raise?
            raise_from = max(end - (j-peak)*R, 0)

            use = raise_to - raise_from
            if use >= 0:
                return use*v[peak] + \
                        res_for(i, peak, start, raise_to) + \
                        res_for(peak+1, j, min(raise_from+R,E), end)
            else:
                print >> stderr, i, j, start, end, v[i:j], raise_to, raise_from
                assert False, "Not satisflable..."


        return res_for(0, N, E, 0)

    for case in xrange(1, T+1):
        print "Case #%d: %s" % (case, test())
        sys.stdout.flush()

if __name__ == '__main__':
    mainLarge()
