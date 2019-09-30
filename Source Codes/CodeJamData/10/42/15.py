
inf=2*10**20

def inv(x):
    return P-int(x)

def xl(l):
    return xrange(len(l))

debug=False
for case in range(input()):
    print "Case #"+str(case+1)+":",
    P=input()
    need=map(inv,raw_input().split())
    costs=[]
    for i in xrange(P):
        costs=map(int,raw_input().split())+costs
    v=[[inf for i in xrange(P+1)] for j in xrange(2**(P+1)-1)]
    if debug: print len(v),2**(P+1)-1,2**P
    leaves=2**P-1
    for (i,x) in enumerate(need):
        for j in xrange(x,P+1):
            v[leaves+i][j]=0
    for n in xrange(leaves-1,-1,-1):
        if debug: print n,2*n+1,2*n+2
        for i in xrange(P+1):
            if i==P:
                buy=inf
            else:
                buy=v[2*n+1][i+1]+v[2*n+2][i+1]+costs[n]
            skip=v[2*n+1][i]+v[2*n+2][i]
            v[n][i]=min(buy,skip)
    print v[0][0]
    if debug:
        print costs
        for (i,x) in enumerate(v): print i,x
