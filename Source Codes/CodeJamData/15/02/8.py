tnum = int(raw_input())
for test in range(tnum):
    n = int(raw_input())
    p = [int(x) for x in raw_input().split()]
    ans = max(p)
    for u in range(1, 1001):
        s = sum((x-1)/u for x in p)
        ans = min(ans, u+s)
    print "Case #{}: {}".format(test+1, ans)
