rl = raw_input
cases = int(rl())
cache = {}

def go(n, status):
    if status == (2 ** n) - 1: return 0.0
    key = (n, status)
    if key in cache: return cache[key]
    ret = 0.0
    for arr in xrange(n):
        wait = 0
        while status & (2 ** ((arr + wait) % n)):
            wait += 1
        ret += (n - wait) + go(n, status + (2 ** ((arr + wait) % n)))
    # if n == 3:
    #     s = ['X' if (status & (2 ** i)) else '.' for i in xrange(n)]
    #     print ''.join(s), '=>', ret / n
    cache[key] = ret / n
    return ret / n
for cc in xrange(cases):
    occupied = rl().strip()
    n = len(occupied)
    status = sum([2**i for i in xrange(n) if occupied[i] == 'X'])
    print 'Case #%d: %.10lf' % (cc+1, go(n, status))

