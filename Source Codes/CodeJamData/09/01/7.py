#!/usr/bin/env python

import re
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

def do_trial(L, pattern, words):
    pattern = re.sub("\(", "[", pattern)
    pattern = re.sub("\)", "]", pattern)
    cre = re.compile(pattern)
    count = 0
    for w in words:
        if cre.match(w):
            count = count + 1
    return count

f = sys.stdin
L, D, N = [int(x) for x in f.readline().split()]
words = [f.readline()[:-1] for i in range(D)]
for i in range(N):
    case = f.readline()[:-1]
    count = do_trial(L, case, words)
    print "Case #%d: %d" % (i+1, count)
