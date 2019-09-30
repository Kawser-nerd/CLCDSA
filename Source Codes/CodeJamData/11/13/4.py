#!/usr/bin/env python

from sys import argv

def score(t,ih,id,s,mem={}):
    if t == 0:
        return s
    h,d = ih[:],id[:]
    x = 0 # Adding rounds is a non-brainer
    while x < len(h):
        hc,hs,ht = h[x]
        if ht >= 1:
            s += hs
            t += ht-1
            h.pop(x)
            h += d[:hc]
            d  = d[hc:]
        else:
            x += 1
    ms = s
    h  = sorted(h,cmp=lambda x,y:cmp((y[1],y[0]),(x[1],x[0])))
    ch = [False]*len(h)
    for x in xrange(1,len(h)):
        for y in xrange(x-1,-1,-1):
            if h[x][0] <= h[y][0]:
                ch[x] = True
                break
    for x in xrange(len(h)):
        if not ch[x]:
            hc,hs,ht = h[x]
            ms = max(ms,score(t-1+ht,h[:x]+h[x+1:]+d[:hc],d[hc:],s+hs))
    return ms

f = open(argv[1],'r')
p = int(f.readline())
for x in xrange(p):
    z = int(f.readline())
    h = [tuple(map(int,f.readline().split())) for y in xrange(z)]
    z = int(f.readline())
    d = [tuple(map(int,f.readline().split())) for y in xrange(z)]
    print 'Case #%d: %s' % (x+1,score(1,h,d,0))
f.close()
