def permgen(k, s=None):
    if s is None:
        s = set(xrange(k))
    if len(s) == 1:
        yield (list(s)[0],)
        return
    for i in s:
        for k in permgen(k, s - set([i])):
            yield k + (i,)

def process(k, str):
    minl = 9999999999
    for perm in permgen(k):
        last = ''
        l = 0
        for i in xrange(len(str)):
            ch = str[i/k*k + perm[i%k]]
            if last != ch: l += 1
            last = ch
        if l < minl: minl = l
    return minl

import sys
next = iter(sys.stdin).next
ncases = int(next())
for i in xrange(ncases):
    k = int(next())
    s = next().strip()
    minlen = process(k, s)
    print 'Case #%d: %d' % (i+1, minlen)
    sys.stdout.flush()

