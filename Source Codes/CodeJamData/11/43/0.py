from sys import stdin

P = range(1000001)
for p in xrange(2,1000):
    if P[p]:
        P[p*p::p] = [0] * (1 + (1000000 / p) - p)
P[1] = 0
P = [p for p in P if p]

for i in xrange(1,1+int(stdin.readline())):
    n = int(stdin.readline())
    k = 2
    ans = 1
    while ((1 << k) <= n):
        lwr = 0
        upr = len(P)
        while (lwr + 1 < upr):
            mid = (lwr + upr) >> 1
            if ((P[mid] ** k) <= n):
                lwr = mid
            else:
                upr = mid
        ans += upr
        k += 1
    if (n == 1): ans = 0
    print "Case #%d: %d" % (i, ans)
