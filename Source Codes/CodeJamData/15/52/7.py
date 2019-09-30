import sys


def compute(N, K, x):
    diffs = [x[i] - x[i - 1] for i in xrange(1, len(x))]
    minDist = 0
    s0 = 0
    v = []
    for i in xrange(K):
        d = diffs[i:len(diffs):K]
        z = [0]
        for j in xrange(len(d)):
            z.append(z[j] + d[j])
        s0 -= min(z)
        v.append(max(z) - min(z))

    m = max(v)
    s1 = s0 + len(v) * m - sum(v)
    if s1 - s0 >= K:
        return m

    s1 = s1 % K
    s0 = s0 % K
    q = x[0] % K
    if s0 <= q and q <= s1:
        return m
    if s1 < s0 and (q >= s0 or q <= s1):
        return m
    return m + 1


def parse():
    N, K = map(int, sys.stdin.readline().strip().split())
    x = map(int, sys.stdin.readline().strip().split())
    return N, K, x


if __name__ == "__main__":
    sys.setrecursionlimit(100000)
    T = int(sys.stdin.readline().strip())
    for i in xrange(T):
        data = parse()
        result = compute(*data)
        print "Case #%d: %s" % (i + 1, result)
