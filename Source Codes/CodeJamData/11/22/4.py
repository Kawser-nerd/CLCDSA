import sys

def case():
    C, D = map(int, raw_input().split())
    start = []
    vendors = []
    pvs = []
    for i in xrange(C):
        p, v = pv = map(int, raw_input().split())
        pvs.append(pv)
        start.append(p)
        vendors.append(v)

    def possible(motion):
        # next allowable final position
        x = start[0] - motion
        for p, v in pvs:
            if p+motion < x:
                return False
            first = max(p-motion, x)
            last = first + (v-1)*D
            if abs(last-p) > motion:
                return False
            x = last + D
        return True

    l = 0.0
    u = 1.0
    while not possible(u):
        l = u
        u *= 2

    while (u-l) > 1e-8:
        m = (u+l) / 2
        if m in (u, l):
            return m
        if possible(m):
            u = m
        else:
            l = m

    return m

T = int(raw_input())
for i in xrange(1, T+1):
    print 'Case #%i: %0.7f' % (i, case())
