def solve():
    x,s,r,t,n = map(int,raw_input().split())
    a = [0]*x
    for _ in xrange(n):
        b,e,w = map(int,raw_input().split())
        for i in xrange(b,e):
            a[i]=w
    #print a
    a.sort()
    for i in xrange(x):
        if t>0:
            tt = 1./(a[i]+r)
            #print t,tt
            if tt<t:
                t-=tt
                a[i]+=r
            else:
                a[i]=1./(t+(1.-t*(a[i]+r))/(a[i]+s))
                t = 0
        else: a[i]+=s
    #a[:t]=[r]*len(a[:t])
    #print a
    return sum(1.0/x for x in a)

t = input()
for i in xrange(t):
    print "Case #%d: %.8f"%(i+1,solve())
