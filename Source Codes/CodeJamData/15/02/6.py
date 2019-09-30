import sys


def compute(D, P):
    best = max(P)
    for n in xrange(1, 1001):
        c = sum(map(lambda x : (x - 1) // n, P))
        if c + n < best:
            best = c + n
        if c == 0:
            break
    return best


def parse():
    D = int(sys.stdin.readline().strip())
    P = map(int, sys.stdin.readline().strip().split())
    return D, P


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
