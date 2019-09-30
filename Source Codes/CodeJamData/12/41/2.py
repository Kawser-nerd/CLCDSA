rl = lambda: map(int, raw_input().split())

def solve():
    n = input()
    a = [rl() for _ in xrange(n)]
    d, l = zip(*a)
    D = input()

    s = [100000000] * n
    for i in xrange(n):
        r = D - d[i]
        if r > l[i]: continue
        s[i] = r

    for i in xrange(n-1, -1, -1):
        for j in xrange(i + 1, n):
            if s[j] > l[j]: continue
            dd = d[j] - d[i]
            if dd > l[i]: break
            if dd < s[j]: continue
            s[i] = min(s[i], dd)
    # print s

    return "YES" if s[0] <= d[0] else "NO"

t = input()
for i in xrange(t):
    print "Case #%d: %s" % (i + 1, solve())
