def solve(s):
    ans=0
    for i in xrange(1,len(s)):
        if(s[i]!=s[i-1]):
            ans+=1
    return ans

t=int(raw_input())
for cas in xrange(1,t+1):
    seq=raw_input()+"+"
    print "Case #{}: {}".format(cas,solve(seq))
