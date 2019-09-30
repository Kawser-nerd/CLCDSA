from itertools import *
from bisect import bisect
from math import log
import sys
facts = [1]
for i in xrange(1,100):
    facts.append(facts[-1]*i)
def choose(n,k):
    return facts[n]/facts[k]/facts[n-k]
lines = open("c.in").read().split("\n")
T = int(lines[0])

def f(P,E,F):
    elements = [[int(i),int(j)] for i,j in izip(E,F)]
    total_elts = sum(f for e,f in elements)
    accounted_for = []
    accounted_for_sums = {0: 1}
    unaccounted_for_elts = dict([int(i),int(j)] for i,j in izip(E,F))
    unaccounted_for_elts[0] -= 1
    while unaccounted_for_elts:
        elt = min(unaccounted_for_elts)
        freq = 1
        # print elt,freq,unaccounted_for_elts
        if unaccounted_for_elts[elt] == 0:
            del unaccounted_for_elts[elt]
            continue
        new_d = dict(accounted_for_sums.iteritems())
        for i in xrange(freq):
            accounted_for.append(elt)
            new_e = (i+1) * elt
            new_f = choose(freq,i+1)
            # print new_e,new_f, "h"
            for e,f in accounted_for_sums.iteritems():
                total_e = new_e + e
                total_f = new_f * f
                # print "add %d %d" % (total_e,total_f)
                new_d[total_e] = new_d.get(total_e,0) + total_f
                unaccounted_for_elts[total_e] = unaccounted_for_elts.get(total_e,0) - total_f
        accounted_for_sums = new_d
        # print elt,freq,unaccounted_for_elts
        # if elt:
        #     del unaccounted_for_elts[elt]
    return ' '.join(str(s) for s in sorted(accounted_for))
curr_i = 1
for i in xrange(1,T+1):
    P = int(lines[curr_i])
    curr_i += 1
    out = f(P,lines[curr_i].split(' '),lines[curr_i+1].split(' '))
    curr_i += 2
    print "Case #%d: %s" % (i, out)