#!/usr/bin/python

def memo(f):
    save = {}
    def func(*args):
        if args in save:
            return save[args]
        ret = f(*args)
        save[args] = ret
        return ret
    return func

def get(n, m, boxes, toys):
    @memo
    def f(aidx, bidx, acount, bcount):
        if aidx >= n or bidx >= m: return 0
        if boxes[aidx][1] != toys[bidx][1]:
            return max(f(aidx+1, bidx, boxes[aidx+1][0], bcount), f(aidx, bidx+1, acount, toys[bidx+1][0]))
        else:
            k = min(acount, bcount)
            acount -= k
            bcount -= k
            if acount == 0:
                aidx += 1
                acount = boxes[aidx][0]
            if bcount == 0:
                bidx += 1
                bcount = toys[bidx][0]
            return k + f(aidx, bidx, acount, bcount)
    return f(0, 0, boxes[0][0], toys[0][0])

t = input()
getnums = lambda: map(int, raw_input().strip().split())
for x in xrange(t):
    n, m = getnums()
    bs = getnums()
    boxes = []
    for y in xrange(n):
        boxes.append((bs[2*y], bs[2*y+1]))
    boxes.append((-1,-1))
    ts = getnums()
    toys = []
    for y in xrange(m):
        toys.append((ts[2*y], ts[2*y+1]))
    toys.append((-2,-2))
    print 'Case #%d: %s' % (x + 1, get(n, m, boxes, toys))
