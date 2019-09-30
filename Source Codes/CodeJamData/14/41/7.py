import sys


def compute(N, X, S):
    s = sorted(S, reverse=True)
    c = 0
    a = 0
    b = N - 1
    while a < b:
        if s[a] + s[b] <= X:
            a += 1
            b -= 1
        else:
            a += 1
        c += 1
    if a == b:
        c += 1
    return c


def parse():
    N, X = map(int, sys.stdin.readline().strip().split())
    S = map(int, sys.stdin.readline().strip().split())
    return N, X, S


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
