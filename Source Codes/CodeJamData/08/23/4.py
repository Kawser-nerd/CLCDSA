#!/usr/bin/env python2.5
import math, sys, os, re

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
        K = getint(file)
        indices = getints(file)[1:]
        answer = run_case(K, indices)
        answerstr = ' '.join(str(x) for x in answer)
        print >> outfile, "Case #%d: %s" % (case+1, answerstr)

def run_case(K, indices):
    order = [0]*K
    remain = list(range(1, K+1))
    residue = 0
    for i in xrange(1, K+1):
        pos = remain[(residue+i-1) % len(remain)]
        residue = (residue+i-1) % len(remain)
        assert order[pos-1] == 0
        order[pos-1] = i
        remain.remove(pos)
    for index in indices:
        yield order[index-1]

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

