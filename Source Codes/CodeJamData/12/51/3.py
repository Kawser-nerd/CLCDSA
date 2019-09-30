import sys

def cmp_fn(x1, x2):
    L1, q1 = x1[1], x1[2]
    L2, q2 = x2[1], x2[2]
    if q1 == 100 and q2 == 100:
        return x1[0] - x1[1]
    if q1 == 100:
        return 1
    if q2 == 100:
        return -1
    if L1 * q2 != L2 * q1:
        return L2 * q1 - L1 * q2
    return x1[0] - x1[1]


def compute(L, P):
    x = [(i, L[i], 100 - P[i]) for i in xrange(len(L))]
    x = sorted(x, cmp=cmp_fn)
    return " ".join([('%d' % x[i][0]) for i in xrange(len(x))])


def parse():
    N = int(sys.stdin.readline().strip())
    L = map(int, sys.stdin.readline().strip().split())
    P = map(int, sys.stdin.readline().strip().split())
    return L, P


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    count = 1
    part = 0
    if len(sys.argv) == 3:
        part = int(sys.argv[1])
        count = int(sys.argv[2])
    for i in xrange(T):
        data = parse()
        if i * count >= part * T and i * count < (part + 1) * T:
            result = compute(*data)
            print "Case #%d: %s" % (i + 1, result)
