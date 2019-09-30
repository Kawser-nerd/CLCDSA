import sys

def worst_record(p, n):
    better = 0
    record = []
    for i in xrange(n):
        if better >= p - 1:
            record.append("W")

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, P = map(int, f.readline().split())

        p = 2**N - 1
        r = 2**N - 1

        b = 0
        for i in xrange(N):
            if r < P:
                b = max(b, p)
            p -= 2**i
            r -= 2**(N-i-1)

        g = 0
        p = 0
        r = 0
        if P == 2**N:
            g = 2**N-1
        for i in xrange(N):
            if r < P:
                g = max(g, p)
            p += 2**(i+1)
            r += 2**(N-i-1)

        print "Case #%d: %d %d" % (_T+1, g, b)
