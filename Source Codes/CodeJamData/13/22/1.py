
from __future__ import division
import sys

vstup = map(int, sys.stdin.read().split())


t = vstup.pop(0)


def level(x, y):
    return (y + abs(x)) // 2 + 1


def findout(n, x, y):
    x = abs(x)
    numfull = 0
    fullsize = 1
    while fullsize <= n:
        numfull += 1
        n -= fullsize
        fullsize += 4
    if level(x, y) <= numfull:
        return 1.0
    if n == 0:
        return 0.0
    if level(x, y) != numfull + 1 or x == 0:
        return 0.0
    fullsize -= 1
    half = fullsize//2
    want = y + 1
#    print >>sys.stderr, fullsize, half, n, want

    dp = [[0.0]*(half+1), None]
    dp[0][0] = 1.0
    for i in xrange(n):
        oi = i%2
        ni = 1-oi
        dp[ni] = [0.0]*(half+1)
#        print i, dp[oi]
        for on in xrange(half+1):
            off = i - on
            if on == half: dp[ni][on] += dp[oi][on]
            elif off == half: dp[ni][on+1] += dp[oi][on]
            else:
                dp[ni][on] += dp[oi][on]/2
                dp[ni][on+1] += dp[oi][on]/2
    res = 0.0
    for on in xrange(half+1):
        if on >= want: res += dp[n%2][on]
    return res


for tc in xrange(t):
    n = vstup.pop(0)
    x = vstup.pop(0)
    y = vstup.pop(0)
    #print (n, x, y)
    print "Case #{}: {:.9f}".format(tc+1, findout(n, x, y))
