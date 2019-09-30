#!/usr/bin/env python2.5
import math, sys, os, re, string

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

def recurse(ings, start):
    return [recurse(ings, x) for x in ings[start]]

def run_file(file, out=None):
    if out is None and isinstance(file, basestring) and file.endswith('.in'):
        out = file[:-3]+'.out'
    if out is None: outfile = sys.stdout
    else: outfile = open(out, 'w')
    if isinstance(file, basestring): file = open(file)


    ncases = getint(file)
    for case in xrange(ncases):
        ingredients = {}
        start = None
        ning = getint(file)
        for i in xrange(ning):
            parts = file.readline().strip().split()
            ing = parts[0]
            if start is None: start=ing
            ingredients[ing] = [x for x in parts[2:] if x[0] in string.uppercase]

        tree = recurse(ingredients, start)
        print "Case", case
        answer = run_case(tree)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def run_case(tree):
    return maxbowls(tree)

def maxbowls(tree):
    subs = [maxbowls(x) for x in tree]
    subs.sort()
    subs.reverse()
    for i in range(len(subs)):
        subs[i] += i
    return max(subs + [len(subs)+1])

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

