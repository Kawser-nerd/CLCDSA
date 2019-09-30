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
def is_happy(n, base, possibly_unhappy=frozenset()):
    if n in possibly_unhappy: return False
    if n == 1: return True
    nv = next_val(n, base)
    possibly_unhappy = possibly_unhappy.union([n])
    return is_happy(nv, base, possibly_unhappy)

@Memoize
def next_val(v, base):
    if v == 0: return 0
    t = v%base
    return t*t + next_val(v/base, base)

def test():
    assert next_val(10, 10) == 1
    assert next_val(9, 10) == 81
    assert next_val(19, 10) == 82
    assert next_val(4, 2) == 1
    assert is_happy(3, 2)
    assert is_happy(3, 3)
    assert is_happy(143, 2)
    assert is_happy(143, 3)
    assert is_happy(143, 7)
    assert not is_happy(142, 7)

test()
#sys.exit(1)


def do_trial(f):
    bases = [int(x) for x in f.readline().split()]
    N = 2
    while 1:
        ok = True
        for b in bases:
            if not is_happy(N, b):
                N = N + 1
                ok = False
                break
        if ok: break
    return N

f = sys.stdin
count = int(f.readline())
for i in xrange(count):
    v = do_trial(f)
    print "Case #%d: %d" % (i+1, v)
