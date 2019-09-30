import collections
import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, p, q, r, s = map(int, f.readline().split())

        transistors = [(i * p + q) % r + s for i in xrange(N)]
        total = sum(transistors)

        sums = []
        t = 0
        for i in xrange(N):
            sums.append(t)
            t += transistors[i]
        sums.append(t)
        assert t == total

        def can3(p):
            needed = (1 - p) * total
            for i in xrange(N-1, 0, -1):
                if sums[i] <= needed:
                    break
            else:
                return False

            for j in xrange(N-1, i-1, -1):
                if sums[j+1] - sums[i] <= needed:
                    break
            else:
                return False

            if total - sums[j+1] <= needed:
                return True
            return False

        def can2(p):
            needed = (1 - p) * total
            for i in xrange(N-1, 0, -1):
                if sums[i] <= needed:
                    break
            else:
                return False

            if total - sums[i] <= needed:
                return True
            return False


        low = 0.0
        high = 1.0
        for i in xrange(40):
            g = (low + high) * 0.5

            if can3(g) or can2(g):
                low = g
            else:
                high = g
        print "Case #%d: %.10f" % (_T+1, low)
