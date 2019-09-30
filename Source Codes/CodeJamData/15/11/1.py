tnum = int(raw_input())
for tcou in range(tnum):
    n = int(raw_input())
    s = [int(x) for x in raw_input().split()]
    ans1 = 0
    r = 0
    ans2 = 0
    for x, y in zip(s[:-1], s[1:]):
        if y<x:
            ans1 += x-y
        r = max(r, x-y)
    for x, y in zip(s[:-1], s[1:]):
        ans2 += min(r, x)
    print "Case #{}: {} {}".format(tcou+1, ans1, ans2)
