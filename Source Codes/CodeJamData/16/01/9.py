
def test(n):
    if n == 0:
        return "INSOMNIA"
    digs = set()
    for i in xrange(1, 10000000000000):
        digs |= set(str(i * n))
        if len(digs) == 10:
            return i * n

N = input()
for i in xrange(N):
    n = input()
    print "Case #%d: %s" % (i + 1, test(n))
