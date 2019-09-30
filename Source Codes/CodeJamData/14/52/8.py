import sys


def get_best(P, Q, H, G, buf, pos, free):
    if buf[pos][free] >= 0:
        return buf[pos][free]
    if pos == len(H):
        return 0
    # Tower gets this:
    n = (H[pos] + Q - 1) // Q
    a = get_best(P, Q, H, G, buf, pos + 1, free + n)
    # Diana tries to get this
    m = (H[pos] -1) // Q
    remaining = H[pos] - m * Q
    b = 0
    if (free + m) * P >= remaining:
        n = (remaining + P - 1) // P
        b = G[pos] + get_best(P, Q, H, G, buf, pos + 1, free + m - n)
    buf[pos][free] = max(a, b)
    return buf[pos][free]


def compute(P, Q, N, H, G):
    buf = [[-1] * 10010 for i in xrange(200)]
    return get_best(P, Q, H, G, buf, 0, 1)


def parse():
    P, Q, N = map(int, sys.stdin.readline().strip().split())
    H = []
    G = []
    for i in xrange(N):
        h, g = map(int, sys.stdin.readline().strip().split())
        H.append(h)
        G.append(g)
    return P, Q, N, H, G


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
