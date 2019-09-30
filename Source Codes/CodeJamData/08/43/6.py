#!/usr/bin/env python2.5
import math, sys, os, re, psyco
psyco.profile()

DEBUG = False
def getline(file, types):
    parts = file.readline().strip().split()
    got = []
    for i in xrange(len(parts)):
        got.append(types[i](parts[i]))
    return got

def getints(file):
    parts = file.readline().strip().split()
    return [int(x) for x in parts]

def getint(file):
    ints = getints(file)
    assert len(ints) == 1
    return ints[0]

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)


    ncases = getint(file)
    for case in xrange(ncases):
        nships = getint(file)
        ships = []
        for s in xrange(nships):
            ships.append(getints(file))
        answer = run_case(ships)
        print >> outfile, "Case #%d: %6.6f" % (case+1, answer)

def distance(x0, y0, z0, ships):
    maxdist = 0
    for x,y,z,p in ships:
        dist = float(abs(x-x0) + abs(y-y0) + abs(z-z0))/p
        if dist > maxdist: maxdist = dist
    return maxdist

def run_case(ships):
    step = 250000.0
    x0 = y0 = z0 = 500000
    bestdist = 999999999
    while step > 0.0000001:
        bestdist = 999999999
        bestcoords = None
        for x1 in (x0+step, x0-step):
            for y1 in (y0+step, y0-step):
                for z1 in (z0+step, z0-step):
                    dist = distance(x1, y1, z1, ships)
                    if dist < bestdist:
                        bestdist = dist
                        bestcoords = (x1, y1, z1)
        x0, y0, z0 = bestcoords
        step /= 2
    return bestdist

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

