import itertools
def solve(n,k,p):
    global memo
    p.sort()
    opts = []
    l=k/2
    #for pos in itertools.combinations(p,k):
    for i in xrange(0,k+1):
        memo={}
        q=p[:i]+p[n-(k-i):]
        opts.append(prob(l,l,q))
    return max(opts)

memo={}

def prob(a,b,q):
    global memo
    if (a,b,len(q)) in memo:
        return memo[(a,b,len(q))]
    else:
        ans=0
        if(a==0):
            ans=1.
            for i in q[:b]:
                ans*=(1.-i)
        elif(b==0):
            ans=1.
            for i in q[:a]:
                ans*=i
        else:
            ans=q[a+b-1]*prob(a-1,b,q)+(1.-q[a+b-1])*prob(a,b-1,q)
        memo[(a,b,len(q))]=ans
    return ans

t = int(raw_input())
for cas in xrange(1,t+1):
    n,k=map(int,raw_input().split())
    p = map(float,raw_input().split())
    print "Case #{}: {}".format(cas,solve(n,k,p))
