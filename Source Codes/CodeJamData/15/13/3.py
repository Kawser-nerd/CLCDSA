import sys


def orientation(x, y, z):
    return x[0] * y[1] + y[0] * z[1] + z[0] * x[1] - x[0] * z[1] - y[0] * x[1] - z[0] * y[1]


def compute(N, p):
    if N == 1:
        return "\n0"
    mintrees = [N] * N
    for i in xrange(N):
        for j in xrange(i + 1, N):
            a, b = 0, 0
            for k in xrange(N):
                d = orientation(p[i], p[j], p[k])
                if d < 0:
                    a += 1
                if d > 0:
                    b += 1
            mintrees[i] = min(mintrees[i], a, b)
            mintrees[j] = min(mintrees[j], a ,b)
    return "\n".join(map(str, mintrees))


def parse():
    N = int(sys.stdin.readline().strip())
    p = []
    for i in xrange(N):
        p.append(map(int, sys.stdin.readline().strip().split()))
    return N, p


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d:\n%s" % (i + 1, result)
