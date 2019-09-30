import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    t = int(f.readline())
    for _t in xrange(t):
        a, b = map(int, sys.stdin.readline().split())
        p = map(float, sys.stdin.readline().split())
        assert len(p) == a

        best = float(b+2)
        # print best

        # print a,b
        pright = 1.0
        for i in xrange(0, a+1):
            pright = 1.0
            for j in xrange(a-i):
                pright *= p[j]
            expected = pright * (i + i + (b-a) + 1) + (1 - pright) * (i + i + (b-a) + 1 + b + 1)
            # print i, expected
            best = min(best, expected)

        print "Case #%d: %.6f" % (_t + 1, best)
