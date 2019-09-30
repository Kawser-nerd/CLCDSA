def solve():
    n = int(raw_input())
    a = []
    for i in xrange(n):
        d, h, m = map(int, raw_input().split())
        for j in xrange(h):
            a.append((360 - d, m + j))
    N = len(a)
    if N <= 1:
        return 0
    b = []
    for i, x in enumerate(a):
        t = 1.0 * x[0] * x[1]
        b.append((t, i))
    b.sort()
    i, j = b[1][1], b[0][1]
    if a[i][0] * a[i][1] >= (360 + a[j][0]) * a[j][1]:
        return 1
    else:
        return 0

T = int(raw_input())
for t in xrange(T):
    print "Case #%d: %d" % (t + 1, solve())
