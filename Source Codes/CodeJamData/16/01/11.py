#!/usr/bin/env python

import collections

import math
import re
import sys

INPUT = "tiny"
INPUT = "A-small-attempt0.in"
INPUT = "A-large.in"
#INPUT = "C-small-attempt0.in"

def debug(*args):
    return
    sys.stderr.write(str(args) + "\n")

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

def do_trial(N):
    seen = [False] * 10
    for i in range(10000000):
        k = (i+1) * N
        for d in str(k):
            seen[int(d)] = True
        if all(seen):
            return k
    return "INSOMNIA"

f = file(INPUT)
T = int(f.readline()[:-1])
for i in range(T):
    N = int(f.readline()[:-1])
    v = do_trial(N)
    print "Case #%d: %s" % (i+1, v)
