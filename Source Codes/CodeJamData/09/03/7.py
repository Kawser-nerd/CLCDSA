#!/usr/bin/env python

import re
import sys

sys.setrecursionlimit(10000)

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
def find_subset(text_to_find, text_to_search):
    if len(text_to_find) == 0: return 1
    if len(text_to_search) == 0: return 0
    if text_to_find[0] == text_to_search[0]:
        return (find_subset(text_to_find[1:], text_to_search[1:]) + find_subset(text_to_find, text_to_search[1:])) % 10000
    return find_subset(text_to_find, text_to_search[1:])

f = sys.stdin
N = int(f.readline())
for i in range(N):
    text_to_find = "welcome to code jam"
    T = f.readline()[:-1]
    r = find_subset(text_to_find, T)
    print "Case #%d: %04d" % (i+1, r)
