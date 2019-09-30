import sys


def calc(x, y, b):
    ymin = min(y)
    count = 0
    total = 0
    for i in xrange(len(y)):
        if y[i] == ymin:
            count += 1
            total += y[i] - x[i]
    res = total * 36.0 / count - b
    return res


def compute(B, N, x):
    for i in xrange(N, 37):
        x.append(0)
    x = sorted(x, reverse=True)
    rmax = 0.0
    y = [x[i] for i in xrange(len(x))]
    r = calc(x, y, 0)
    if r > rmax:
        rmax = r
    for i in xrange(B):
        jmin = 0
        hmin = y[0]
        for j in xrange(37):
            if y[j] < hmin:
                hmin = y[j]
                jmin = j
        y[jmin] += 1
        r = calc(x, y, i + 1)
        if r > rmax:
            rmax = r
    return rmax


def parse():
    B, N = map(int, sys.stdin.readline().strip().split())
    x = map(int, sys.stdin.readline().strip().split())
    return B, N, x


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
