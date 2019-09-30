t = input()
for tc in xrange(t):
    n = input() + 1
    s = str(n)
    l = len(s)
    dp = [[-1 for j in xrange(10)] for i in xrange(l + 1)]
    dp[0][9] = 0
    ans = 0
    for i in xrange(l):
        for k in xrange(int(s[i])):
            t = s[:i] + str(k) + '9' * (l - i - 1)
            ok = 1
            for j in xrange(l - 1):
                ok &= int(t[j]) <= int(t[j + 1])
            if ok:
                ans = max(ans, int(t))
    print "Case #{0}: {1}".format(str(tc + 1), str(ans))
