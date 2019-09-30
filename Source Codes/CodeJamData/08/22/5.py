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
        A, B, P = getints(file)
        answer = run_case(A, B, P)
        print >> outfile, "Case #%d: %d" % (case+1, answer)

isprime = [True] * 10000001
isprime[0] = False
isprime[1] = False

for i in xrange(10000001):
    if isprime[i]:
        for j in xrange(i, 10000001, i):
            isprime[j] = False
        isprime[i] = True

def run_case(A, B, P):
    buckets = [[i] for i in range(A, B+1)]
    whichbucket = [i-A for i in range(A, B+1)]
    for p in xrange(P, B-A+1):
        if not isprime[p]: continue
        start = p*(A//p)
        if (start < A): start += p
        #print 'prime:', p, start
        for j in xrange(start+p, B+1, p):
            #print whichbucket
            #print buckets
            if whichbucket[start-A] != whichbucket[j-A]:
                # merge two buckets
                #print 'merged'
                oldbucket = whichbucket[j-A]
                for b in buckets[whichbucket[j-A]]:
                    whichbucket[b-A] = whichbucket[start-A]
                buckets[whichbucket[start-A]] += buckets[oldbucket]
                buckets[oldbucket] = []
    tot = 0
    for bucket in buckets:
        if len(bucket) > 0: tot += 1
    return tot

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

