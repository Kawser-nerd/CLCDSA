#!/usr/bin/env python

import collections

import math
import re
import sys

#sys.setrecursionlimit(50)

INPUT = "tiny"
INPUT = "C-large.in"
#INPUT = "C-small-attempt1.in"

class Prime(object):
    def __init__(self):
        self.primes = [2]
        self.N = 2

    def prime_iter(self, S=2):
        for n in self.primes:
            if n >= S:
                yield n
        to_check = self.primes[-1]
        while 1:
            to_check += 1
            if self.is_prime(to_check):
                self.primes.append(to_check)
                if n >= S:
                    yield to_check

    def is_prime(self, n):
        if n in self.primes:
            return True
        if n < self.primes[-1]:
            return False
        for p in self.prime_iter():
            if p * p > n:
                return True
            if n % p == 0:
                return False


PRIMES = set()
for i in Prime().prime_iter():
    if i > 10000:
        break
    PRIMES.add(i)


def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")


def find_next_coin(fv):
    while 1:
        fv_bin = bin(fv)[2:]
        divs = []
        for k in range(2, 11):
            v = int(fv_bin, k)
            for p in PRIMES:
                if v % p == 0:
                    divs.append(p)
                    if len(divs) == 9:
                        return fv, divs
                    break
            else:
                break
        fv += 2

def do_trial(N, J):
    fv = (1 << (N-1)) + 1
    out = []
    while len(out) < J:
        fv, divs = find_next_coin(fv)
        out.append((bin(fv)[2:], divs))
        fv += 2
    def rep(o, l):
        return "%s %s" % (o, " ".join(str(d) for d in l))
    return "\n%s" % "\n".join([rep(o, l) for o, l in out])

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N, J = [int(x) for x in f.readline().split()]
    v = do_trial(N, J)
    print "Case #%d: %s" % (i+1, v)
