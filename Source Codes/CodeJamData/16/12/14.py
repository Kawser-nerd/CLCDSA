tt = int(raw_input())
for t in xrange(1, tt+1):
    n = int(raw_input())
    x = [0] * 2502
    for i in xrange(2*n-1):
        s = map(int, raw_input().strip().split())
        for v in s:
            x[v] += 1
    a = []
    for v in xrange(2502):
        if x[v] % 2 == 1:
            a.append(v)
    ans = ' '.join(map(str, a))
    print 'Case #%d: %s' % (t, ans)