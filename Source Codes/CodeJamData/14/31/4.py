import sys

def gcd(a, b):
    if a > b:
        a, b = b, a
    if a == 0:
        return b
    return gcd(b % a, a)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        P, Q = map(int, f.readline().split('/'))
        g = gcd(P, Q)
        P /= g
        Q /= g

        n = 0
        first = 10000000
        while Q & 1 == 0:
            n += 1
            if P >= Q/2:
                first = min(first, n)
            Q >>= 1

        if Q != 1:
            print "Case #%d: impossible" % (_T+1)
        else:
            assert n != 0
            assert 0 < first < 1000
            print "Case #%d: %d" % (_T+1, first)
