tnum = int(raw_input())
for test in range(tnum):
    _, s = raw_input().split()
    s = s.strip()
    t = 0
    ans = 0
    for i, x in enumerate(s):
        ans = max(ans, i-t)
        t += int(x)
    print "Case #{}: {}".format(test+1, ans)
