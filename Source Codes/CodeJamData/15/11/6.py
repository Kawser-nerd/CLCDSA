import sys


def compute(N, m):
    nmin = 0
    nmax = 0
    maxdelta = 0
    for i in xrange(1, N):
        if m[i] < m[i - 1]:
            delta = m[i - 1] - m[i]
            nmin += delta
            if delta > maxdelta:
                maxdelta = delta
    for i in xrange(1, N):
        nmax += min(maxdelta, m[i - 1])
    return "%s %s" % (nmin, nmax)


def parse():
    N = int(sys.stdin.readline().strip())
    m = map(int, sys.stdin.readline().strip().split())
    return N, m


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
