d = {}

def calc(p, release):
    if not release: return 0
    rstr = ','.join(str(s) for s in release)
    if (p, rstr) in d: return d[p, rstr]
    res = min(p - 1 + calc(r - 1, [x for x in release if x < r]) + calc(p - r, [x - r for x in release if x > r]) for r in release)
    d[p, rstr] = res
    return res

N = input()
for i in xrange(N):
    P, Q = [int(s) for s in raw_input().split()]
    release = [int(s) for s in raw_input().split()]
    print 'Case #%i: %i' % (i+1, calc(P, release))
