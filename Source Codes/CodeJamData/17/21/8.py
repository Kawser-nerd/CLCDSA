ip = lambda : map(int, raw_input().split())

def solve(cas):
    d, n = ip()
    h = []
    for i in xrange(n):
        h.append(ip())
    h.sort()
    h.reverse()
    ret = 0.0
    prev = 0
    for x in h:
        now = (d - x[0]) * 1.0 / x[1]
        prev = max(prev, now)
        ret = max(ret, prev)
    print "Case #%d: %.10f" % (cas, d / ret)

for i in xrange(int(raw_input())):
    solve(i + 1)
