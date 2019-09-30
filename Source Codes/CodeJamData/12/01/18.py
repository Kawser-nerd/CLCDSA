#!/usr/bin/python

import sys, re, string, math, fractions, itertools
from fractions import Fraction

ssr = sys.stdin.readline
ssw = sys.stdout.write
def rdline(): return ssr().strip()
def rdstrs(): return ssr.split()
def rdints(): return map(int, ssr().split())

A = """a zoo
our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up"""

B = """y qee
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv"""


d = {}
e = {}

A = A.strip()
B = B.strip()
assert len(A) == len(B)

for (c1, c2) in zip(A,B):
    if c1 in e:
        assert e[c1] == c2
    else:
        e[c1] = c2
    if c2 in d:
        assert d[c2] == c1
    else:
        d[c2] = c1

nod = ""
noe = ""
for cc in range(97, 97+26):
    c = chr(cc)
    if not c in d: nod += c
    if not c in e: noe += c

assert len(nod)==len(noe)
assert len(nod)<=1
if nod:
    d[nod] = noe
    e[noe] = nod


def do_one_case(cnum):
    s = rdline()
    ct = "".join(d[c] for c in s)
    print "Case #%d: %s" % (cnum, ct)


def main():
    N = int(rdline())
    for i in range(N):
        do_one_case(i+1)


if __name__ == "__main__":
    main()
