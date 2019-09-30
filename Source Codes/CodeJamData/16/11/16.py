def solve(s):
    ans = ""
    for c in s:
        if ans+c<c+ans:
            ans=c+ans
        else:
            ans=ans+c
    return ans
t = int(raw_input())
for cas in xrange(1,t+1):
    ans = solve(*raw_input().split())
    print "Case #{}: {}".format(cas,ans)
