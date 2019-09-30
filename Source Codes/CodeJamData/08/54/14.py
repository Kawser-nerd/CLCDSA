#!/usr/bin/env python

import sys

CACHE={}
def do_count(x, y, rooks, h, w):
    k = (x, y, rooks, h, w)
    p = (x,y)
    if CACHE.has_key(k): return CACHE[k]
    if p in rooks: return 0
    if x>h or y>w: return 0
    if x==h and y==w: return 1
    count = 0
    count = count + do_count(x+2, y+1,rooks, h,w)
    count = count + do_count(x+1, y+2,rooks, h,w)
    count %= 10007
    CACHE[k]=count
    #print k, count
    return count

def do_trial(f):
    H,W,R = [int(x) for x in f.readline().split()]
    rooks = set()
    for i in range(R):
        rooks.add(tuple([int(x) for x in f.readline().split()]))
    rooks = frozenset(rooks)

    global CACHE
    CACHE={}

    return do_count(1,1,rooks,H,W)

f = sys.stdin
#f = file("tiny.in")
count = int(f.readline())
for i in range(count):
    r = do_trial(f)
    print "Case #%d: %s" % (i+1, r)
