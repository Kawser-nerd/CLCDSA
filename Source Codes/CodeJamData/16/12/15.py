t = int(raw_input())
for cas in xrange(1,t+1):
    n=int(raw_input())
    ct = dict(zip(xrange(1,2501),[0 for i in xrange(1,2501)]))
    for i in xrange(1,2*n):
        nums = map(int,raw_input().split())
        for num in nums:
            ct[num]+=1
    ans = []
    for i in ct:
        if ct[i]%2==1:
            ans.append(i)
    ans.sort()
    ans = " ".join(map(str,ans))
    print "Case #{}: {}".format(cas,ans)
