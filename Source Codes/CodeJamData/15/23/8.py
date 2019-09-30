from collections import deque
INF=1e50
EPS=1e-9
def tinter(x,y):
    a=list(x)
    b=list(y)
    if(a[1]==b[1]):
        return -1
    if(a[1]>b[1]):
        a,b=b,a
    if(b[0]>=a[0]-EPS):
        b[0]-=360
    return (a[0]-b[0])/(b[1]-a[1])

def evolve(x,t):
    ans =x[0]+t*x[1]
    return (ans,x[1])

def reduce(l):
    ans = l[0]
    while(ans>=360):
        ans-=360
    return (ans,l[1])

def solve(hikers):
    n=len(hikers)
    st=[]
    for i in hikers:
        st.append((float(i[0]),1./i[1]))
    st.sort()
    if(n==1):
        return 0
    t = tinter(st[0],st[1])
    if(st[0][1]>st[1][1]):
        p=evolve(st[0],t)
        q=evolve(st[1],t)
        s = tinter(p,q)
        f=evolve(q,s)
        if(f[0]<360+EPS):
            return 1
        else:
            return 0
    else:
        q=evolve(st[0],t)
        if(q[0]<360+EPS):
            return 1
        else:
            return 0


tcases=int(raw_input())
for cas in xrange(1,tcases+1):
    n=int(raw_input())
    hikers=[]
    for i in xrange(n):
        d,h,m=map(int,raw_input().split())
        for i in xrange(h):
            hikers.append((d,m+i))
    print "Case #{}: {}".format(cas,solve(hikers))
