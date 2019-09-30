#!/usr/bin/python
import sys
from sys import stderr

def Solve(bag):
    print >>stderr, bag
    total = 0
    for c in bag:
        total ^= c
    if total != 0:
        return -1
    minimum = min(bag)
    suma = sum(bag)
    return suma - minimum

f = open(sys.argv[1])

T = int(f.readline())
for t in range(T):
    f.readline()
    bag = map(int,f.readline().split())
    sol = Solve(bag)
    if sol == -1:
        ssol = "NO"
    else:
        ssol = str(sol)
    print "Case #%d: %s" % (t+1, ssol)

