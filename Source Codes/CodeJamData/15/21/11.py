from collections import deque
def solve(n, d=1):
    if len(n) == 1:
        return int(n)
    h = d / 2
    r = d - h
    if len(n) > d:
        res = solve(n, d + 1)
        res += (10 ** h) + (10 ** r) - 1
        return res
    s = n[:h][::-1]
    t = int(s)
    if n[h:] == "0" * r:
        s = int(n[:h]) - 1
        s = str(s)[::-1]
        t = int(s)
    res = t + 1
    s = s[::-1] + "0" * (r - 1) + "1"
    res += int(n) - int(s)
    res = min(res, int(n) - (10 ** (d - 1)))
    return res

"""
dp = [10 ** 9] * 100000
def go():
    que = deque([0])
    dp[0] = 0
    while que:
        x = que.popleft()
        if x == 99999:
            break
        if dp[x+1] == 10 ** 9:
            dp[x+1] = dp[x] + 1
            que.append(x+1)
        y = int(str(x)[::-1])
        if dp[y] == 10 ** 9:
            dp[y] = dp[x] + 1
            que.append(y)
go()
for i in xrange(0, 100000):
    k = solve(str(i))
    if k != dp[i]:
        print i, dp[i], k
"""

T = int(raw_input())
for t in xrange(T):
    N = raw_input().strip()
    print "Case #%d: %d" % (t + 1, solve(N))
