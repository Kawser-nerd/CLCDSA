#!/usr/bin/env python

import sys

def do_trial(f):
    N = int(f.readline())
    M = int(f.readline())
    faves = []
    for i in range(M):
        v = [int(x) for x in f.readline().split()][1:]
        malted = None
        unmalted_set = set()
        for j in range(0,len(v),2):
            if v[j+1]:
                malted = v[j]
            else:
                unmalted_set.add(v[j])
        faves.append((malted, unmalted_set))
    must_be_malted = set()
    while 1:
        all_fine = True
        no_updates = True
        #print "MBM->", must_be_malted

        for m, u in faves:
            u = u.difference(must_be_malted)
            #print "mu->", m,u
            if m is not None:
                if m in must_be_malted:
                    continue

            if len(u) == 0:
                all_fine = False
                if m is None: break
                must_be_malted.add(m)
                no_updates = False
                continue
        if all_fine or no_updates: break
    if not all_fine: return "IMPOSSIBLE"
    return " ".join(['1' if ((x+1) in must_be_malted) else '0' for x in range(N)])

f = sys.stdin
#f = file("mine")
#f = file("B-small-attempt0.in.txt")
#f = file("z")
count = int(f.readline())
for i in xrange(count):
    v = do_trial(f)
    print "Case #%d: %s" % (i+1, v)
