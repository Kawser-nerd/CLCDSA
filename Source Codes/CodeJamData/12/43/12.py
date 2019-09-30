import sys


def do_part(idx, h, x1, x2):
    # print "Doing part %d %d" % (x1, x2)
    if x2 - x1 < 2:
        return True
    h1 = h[x1]
    h2 = h[x2]
    # print "Heights %d %d" % (h1, h2)
    y = []
    i = x1 + 1
    while i < x2:
        if idx[i] > x2 + 1 or idx[i] <= i + 1:
            return False
        y.append(i)
        i = idx[i] - 1
    for j in xrange(len(y) - 1, -1, -1):
        i = y[j]
        if j == len(y) - 1:
            h[i] = h1 + int((h2 - h1) * (i - x1) / (x2 - x1))
            while (h[i] - h1) * (x2 - x1) >= (h2 - h1) * (i - x1):
                h[i] -= 1
        else:
            a = idx[i] - 1
            ha = h[a]
            b = idx[a] - 1
            hb = h[b]
            h[i] = ha - int((hb - ha) * (a - i) / (b - a))
            while (ha - h[i]) * (b - a) <= (hb - ha) * (a - i):
                h[i] -= 1
    # print "y = %s" % y
    if not do_part(idx, h, x1, y[0]):
        return False
    for i in xrange(0, len(y) - 1):
        if not do_part(idx, h, y[i], y[i + 1]):
            return False
    return do_part(idx, h, y[-1], x2)


def compute(N, idx):
    h = [1000000000] * N
    i = 0
    while i < N - 1:
        if idx[i] > N or idx[i] <= i + 1:
            return "Impossible"
        if not do_part(idx, h, i, idx[i] - 1):
            return "Impossible"
        i = idx[i] - 1
    m = min(h)
    return " ".join(["%d" % (i - m) for i in h])


def parse():
    N = int(sys.stdin.readline().strip())
    idx = map(int, sys.stdin.readline().strip().split(' '))
    return (N, idx)


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
