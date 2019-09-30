def solve():
    d = int(raw_input())
    p = map(int, raw_input().split())
    ans = max(p)
    for i in xrange(1, max(p)):
        t = 0
        for x in p:
            q, r = divmod(x, i)
            if r:
                t += 1
            t += q - 1
        if ans > t + i:
            ans = t + i
    return ans

T = int(raw_input())
for i in xrange(T):
    print "Case #%d: %d" % (i + 1, solve())
