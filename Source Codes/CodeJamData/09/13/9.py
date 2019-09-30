#!/usr/bin/env python

import sys

class Memoize:
    def __init__(self,function):
        self._cache = {}
        self._callable = function
            
    def __call__(self, *args, **kwds):
        cache = self._cache
        key = self._getKey(*args,**kwds)
        try: return cache[key]
        except KeyError:
            cachedValue = cache[key] = self._callable(*args,**kwds)
            return cachedValue
    
    def _getKey(self,*args,**kwds):
        return kwds and (args, ImmutableDict(kwds)) or args    

@Memoize
def fact(N):
    if N<2: return 1
    return N * fact(N-1)

def inv_fact(N):
    if N < 0: return 0
    return 1.0/fact(N)

def expected_probs(C, N, probs):
    new_probs = [0.0] * len(probs)
    #print probs
    for i, old_prob in enumerate(probs):
        #print "**********", i
        for c in xrange(0, C-i+1):
            #print "***", i, n, old_prob, C, N, new_probs
            p = prob(C-i, i, c, N-c)
            #print "%d card types; %d cards per pack; %d cards collected; %d new found with prob %f" % (C, N, i, c, p)
            new_probs[i+c] += old_prob * prob(C-i, i, c, N-c)
            #print "new_probs", new_probs
    return new_probs

@Memoize
def choose(a, b):
    return fact(a)/fact(b)/fact(a-b)

@Memoize
def prob(K0, K1, P0, P1):
    import pdb
    #pdb.set_trace()
    # K0+K1 = C
    # P0+P1 = N
    P = 1.0 * fact(K0+K1-P0-P1) * inv_fact(K0+K1) * fact(K0) * inv_fact(K0-P0) * fact(K1) * inv_fact(K1-P1) * choose(P0+P1, P0)
    return P

#print prob(1, 1, 1, 0)
#print prob(1, 1, 0, 1)

def test():
    #assert choose(5, 3) == 10
    #assert prob_we_get(2, 1, 0, 0) == 0.0
    total = 0.0
    for i in range(3):
        p1 = prob(3, 4, i, 2-i)
        print "p1=", p1
        total += p1
    #print "*******", total
    assert total == 1.0

#test()
#sys.exit(1)




def do_trial(f):
    C, N = [int(x) for x in f.readline().split()]
    #print C, N
    probs = [1.0]
    for i in range(C):
        probs.append(0.0)
    COUNT = 0
    EXPECTED = 0.0
    while 1:
        #print "-"*50, COUNT, probs
        new_probs = expected_probs(C, N, probs)
        COUNT = COUNT + 1
        EXPECTED += COUNT * (new_probs[-1] - probs[-1])
        probs = new_probs
        if probs[-1] > 1.0-1e-10:
            break
    return EXPECTED

f = sys.stdin
count = int(f.readline())
for i in xrange(count):
    v = do_trial(f)
    print "Case #%d: %f" % (i+1, v)
