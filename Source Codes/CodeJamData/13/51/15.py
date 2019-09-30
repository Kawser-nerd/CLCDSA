from sys import stdin
import heapq
def solve():
    b, n = map(int, stdin.readline().split())
    z = map(int, stdin.readline().split())
    x = z + [0] * (37 - n)
    l = [(i, 0) for i in x]
    heapq.heapify(l)
    res = 0
    for z in xrange(1, b+1):
        x = heapq.heappop(l)
        x = (x[0] + 1, x[1] + 1)
        heapq.heappush(l, x)
        s = 10 ** 20
        t = 0
        u = 0
        for x in l:
            s = min(s, x[0])
        for x in l:
            if s == x[0]:
                t += 1
                u += x[1]
        tmp = 36.0 * u / t - z
        res = max(res, tmp)
    return res
T = int(stdin.readline())
for i in xrange(T):
    print "Case #%d: %.12f" % (i+1, solve())
