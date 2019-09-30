import sys


def compute(smax, x):
    c = 0
    r = 0
    for i, n in enumerate(x):
        if i > c:
            r += 1
            c = i
        c += n
    return r


def parse():
    smax, x = sys.stdin.readline().strip().split()
    smax = int(smax)
    x = map(int, x)
    return smax, x


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
