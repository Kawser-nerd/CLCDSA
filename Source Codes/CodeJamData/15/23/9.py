tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    d = []
    m = []
    for i in xrange(n):
        (dd, hh, mm) = map(int, raw_input().split())
        for j in xrange(hh):
            d.append(dd)
            m.append(mm+j)
    if len(d) < 2:
        ans = 0
    else:
        # only works for <= 2 hikers
        slower = 0 if (m[0] > m[1]) else 1
        dslow = d[slower]
        mslow = m[slower]
        dfast = d[1-slower]
        mfast = m[1-slower]
        ans = 1 if ((360-dslow)*mslow >= (720-dfast)*mfast) else 0
    print 'Case #%d: %d' % (t, ans)