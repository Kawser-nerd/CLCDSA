import sys


def count(B, M, t):
    s = 0
    for i in xrange(B):
        s += t // M[i]
        if t % M[i] != 0:
            s += 1
    return s


def compute(B, N, M):
    a = 0
    b = 10 ** 17
    while a < b:
        m = (a + b) // 2
        if count(B, M, m) < N:
            a = m + 1
        else:
            b = m
    t = a - 1
    r = count(B, M, t)
    for i in xrange(B):
        if t % M[i] == 0:
            if r == N - 1:
                return i + 1
            r += 1
    print "ERROR!!!!!"
    return -1


def parse():
    B, N = map(int, sys.stdin.readline().strip().split())
    M = map(int, sys.stdin.readline().strip().split())
    return B, N, M


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
