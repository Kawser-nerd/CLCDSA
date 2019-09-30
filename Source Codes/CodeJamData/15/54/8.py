import sys


def simplify(ef, d):
    ef2 = []
    for i in xrange(len(ef)):
        e = ef[i][0]
        f = ef[i][1]
        if f == 0:
            continue
        ef2.append(ef[i])
        for x in ef:
            if x[0] != e + d:
                continue
            x[1] -= f
    return ef2


def compute(N, E, F):
    ef = sorted([[E[i], F[i]] for i in xrange(len(E))])
    res = []
    a = ef[-1][1]
    while a > 1:
        res.append(0)
        a /= 2
    for i in xrange(len(ef)):
        ef[i][1] /= ef[-1][1]
    while len(ef) > 1:
        d = ef[-1][0] - ef[-2][0]
        res.append(d)
        ef = simplify(ef, d)
    return ' '.join(map(str, sorted(res)))


def parse():
    N = int(sys.stdin.readline().strip())
    E = map(int, sys.stdin.readline().strip().split())
    F = map(int, sys.stdin.readline().strip().split())
    return N, E, F


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
