from collections import Counter
import sys


def compute(N, A):
    x = [a for b in A for a in b]
    c = Counter(x)
    z = filter(lambda a: a[1] % 2 == 1, c.iteritems())
    z = sorted([int(a[0]) for a in z])
    return " ".join(map(str, z))


def parse():
    N = int(sys.stdin.readline().strip())
    A = []
    for i in xrange(N + N - 1):
        A.append(sys.stdin.readline().strip().split())
    return N, A


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
