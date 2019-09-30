import sys, os

def calcnext(next, cur, d):
    if (cur,d) in next:
        return next[(cur,d)]
    _cur = cur
    _d = d
    t = 0
    if d & 1:
        cur,t = next[(cur,1)]
        d -= 1
    cur, _t = calcnext(next, cur, d/2)
    t += _t
    cur, _t = calcnext(next, cur, d/2)
    t += _t
    next[(_cur, _d)] = (cur, t)
    return (cur, t)


T = int(sys.stdin.readline())
for _t in xrange(T):
    r,k,n = map(int, sys.stdin.readline().split())
    groups = map(int, sys.stdin.readline().split())
    next = {}
    for i in xrange(n):
        t = 0
        for j in xrange(n):
            x = groups[(i+j)%n]
            if t + x > k:
                next[(i, 1)] = ((i+j)%n, t)
                break
            t += x
        else:
            next[(i, 1)] = (i, t)

    total = 0
    cur = 0
    # for i in xrange(r):
        # cur,t = next[(cur, 1)]
        # total += t
    cur, total = calcnext(next, 0, r)
    print "Case #%d: %d" % (_t+1, total)
