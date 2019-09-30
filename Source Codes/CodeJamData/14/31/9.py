def gcd(a,b):
    return gcd(b,a%b) if b else a
pows = [2**i for i in xrange(41)]
for t in xrange(input()):
    a,b = map(int, raw_input().split('/'))
    d = gcd(a,b)
    a /= d
    b /= d
    if b not in pows:
        print 'Case #%d: impossible' % (t+1)
    else:
        res = 0
        while a < b:
            a *= 2
            res += 1
        print 'Case #%d: %d' % (t+1, res)
