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
        K = getint(file)
        string = file.readline().strip()
        answer = run_case(K, string)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def permutate(seq):
    """permutate a sequence and return a list of the permutations"""
    if not seq:
        return [seq]  # is an empty sequence
    else:
        temp = []
        for k in range(len(seq)):
            part = seq[:k] + seq[k+1:]
            #print k, part  # test
            for m in permutate(part):
                temp.append(seq[k:k+1] + m)
                #print m, seq[k:k+1], temp  # test
        return temp

def permutestr(string, seq):
    out = []
    for n in xrange(0, len(string), len(seq)):
        for m in xrange(0, len(seq)):
            out.append(string[n+seq[m]])
    return ''.join(out)

def rlegroups(string):
    char = '!'
    count = 0
    for ch in string:
        if ch != char:
            char = ch
            count += 1
    return count

def run_case(K, string):
    therange = range(K)
    permutations = permutate(therange)
    best = 99999999
    for perm in permutations:
        permuted = permutestr(string, perm)
        score = rlegroups(permuted)
        if score < best: best = score
    return best

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

