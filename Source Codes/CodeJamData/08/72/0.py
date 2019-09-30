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
        skip = getint(file)
        seq = getints(file)
        print "Case", case
        answer = run_case(seq)
        print >> outfile, "Case #%d: %s" % (case+1, answer)

def recurse(seq, prevbits, prevoffset):
    d = len(prevbits)
    if len(seq) < 3:
        yield (prevbits, prevoffset)
        return
    poss = None
    for offset in (0, 1):
        delta = None
        for i in xrange(1, len(seq)):
            if (offset+i) & 1:
                got = (seq[i] - seq[i-1]) % 10007
                if delta is None:
                    delta = got
                elif delta != got:
                    delta = 'inc'
                    break
        if delta == 'inc':
            continue
        elif delta is None:
            raise ValueError
        else:
            if offset == 0: newseq=seq[::2]
            else: newseq = seq[1::2]
            newoffset = prevoffset + (1<<d)*offset
            for got in recurse(newseq, prevbits + [delta], newoffset):
                yield got

def run_case(seq):
    poss = None
    print seq
    for places, offset in recurse(seq, [], 0):
        index = offset + len(seq)
        d=0
        bit = 1<<d
        total = seq[-1]
        
        answered = True
        while bit <= index:
            diff = ((index & bit) - ((index-1) & bit))//bit
            if diff == 0:
                d += 1
                bit = 1<<d
                continue
            if len(places) <= d or places[d] is None:
                return 'UNKNOWN'
            
            total += places[d]*diff
            d += 1
            bit = 1<<d
        
        if answered:
            if poss is None: poss = total
            elif poss != total: return 'UNKNOWN'
    return poss % 10007

def crap():
    pow2 = 1
    digits = 0
    while pow2 < len(seq):
        digits += 1
        pow2 *= 2
    poss = None
    for offset in xrange(0, pow2*2):
        bit = 1
        known = [None] * 11
        
        d = digits
        bit = pow2
        consistent = True
        while bit:
            print bit, known
            for i in xrange(bit, len(seq)):
                if (offset+i) & bit:
                    got = seq[i] - seq[i-bit]
                    if known[d] is not None and known[d] != got:
                        consistent = False
                        break
                    else: known[d] = got
                else:
                    got = - seq[i] + seq[i-bit]
                    if known[d] is not None and known[d] != got:
                        consistent = False
                        break
                    else: known[d] = got
            if not consistent: break
            d -= 1
            bit /= 2

        if not consistent: continue
        index = offset + len(seq)
        total = seq[-1]
        
        d = 0
        bit = 1 << d
        answered = True
        while bit <= pow2:
            diff = ((index & bit) - ((index-1) & bit)) // bit
            if diff == 0:
                d += 1
                bit = 1<<d
                continue
            if known[d] is None:
                answered = False
                break
            total += known[d]*diff
            d += 1
            bit = 1<<d

        if poss is not None and poss != total: return "UNKNOWN"
        poss = total
    return poss

if __name__ == '__main__':
    import sys
    if len(sys.argv) > 1: run_file(sys.argv[1])
    else: run_file(sys.stdin)

