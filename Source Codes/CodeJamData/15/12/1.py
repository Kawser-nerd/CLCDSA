tnum = int(raw_input())
for tcou in range(tnum):
    b, n = [int(x) for x in raw_input().split()]
    m = [int(x) for x in raw_input().split()]
    def tot(t):
        return sum(1+t/x for x in m)
    l = 0
    u=max(m)*n
    while l!=u:
        mid = (l+u)/2
        if tot(mid)<n:
            l = mid+1
        else:
            u = mid
    for x in m:
        n -= (l+x-1)/x
    ans = 0
    for i, x in enumerate(m):
        if l%x==0:
            if n==1:
                ans = i+1
                break
            n -= 1
    print "Case #{}: {}".format(tcou+1, ans)
