import sys


def compute(N, A):
    y = A
    x = sorted(A)
    total = 0
    for k in x:
        z = []
        for i in xrange(len(y)):
            if y[i] == k:
                total += min(i, len(y) - i - 1)
            else:
                z.append(y[i])
        y = z
    return total


def parse():
    N = int(sys.stdin.readline().strip())
    A = map(int, sys.stdin.readline().strip().split())
    return N, A


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
