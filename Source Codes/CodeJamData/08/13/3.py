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

def find_shortest(list_of_lists):
    best_size = len(min(list_of_lists, key=len))
    return [l for l in list_of_lists if len(l) == best_size]

#@Memoize
CACHE={}
def all_paths(se, qs):
    t = (se,qs)
    if CACHE.has_key(t): return CACHE[t]
    if len(qs) == 0:
        v = [[c] for c in se]
        CACHE[t] = v
        return v
    q0 = qs[0]
    l = []
    for c in se:
        if c == q0: continue
        paths = all_paths(se, qs[1:])
        for p in paths:
            if len(p) > 0 and c == p[0]:
                l.append(p)
            else:
                l.append([c] + p)
    l = find_shortest(l)
    CACHE[t] = l
    return l

def choose(n, m):
    pass

def do_trial(f):
    search_engine_count = int(f.readline())
    search_engines = tuple([f.readline()[:-1] for i in xrange(search_engine_count)])
    #print search_engines
    query_count = int(f.readline())
    queries = tuple([f.readline()[:-1] for i in xrange(query_count)])
    #print queries
    v = find_shortest(all_paths(search_engines, queries))[0]
    return len(v)-1

f = sys.stdin
count = int(f.readline())
for i in xrange(count):
    v = do_trial(f)
    print "Case #%d: %d" % (i+1, v)
