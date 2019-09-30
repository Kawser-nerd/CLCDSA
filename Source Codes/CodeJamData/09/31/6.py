from itertools import groupby

T = input()
for i in xrange(T):
    s = raw_input()

    m = len(list(groupby(sorted(s))))
    if m == 1: m = 2

    n = 0
    d = {}
    
    for k, c in enumerate(s):
        if k == 0:
            d[c] = 1
        elif c in d:
            pass
        elif len(d) == 1:
            d[c] = 0
        else:
            d[c] = len(d)
        n *= m
        n += d[c]
    
    print 'Case #%i: %i' % (i+1, n)
