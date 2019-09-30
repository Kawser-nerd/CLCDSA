def solve():
    n, s = raw_input().split()
    ans = t = 0
    for i, c in enumerate(map(int, s)):
        if t < i:
            ans += i - t
            t = i
        t += c
    return ans

T = int(raw_input())
for i in xrange(T):
    print "Case #%d: %d" % (i + 1, solve())
