from collections import deque
def dfs(comp,i):
    if(comp[f[i]]==-1):
        comp[f[i]]=comp[i]
        return dfs(comp,f[i])
    return i

def ct(l,x):
    return len([i for i in l if i==x])

def cyc(cycley,f,i):
    cycley[i]=True
    tot = 1
    at=f[i]
    while(at!=i):
        cycley[at]=True
        tot+=1
        at=f[at]
    return tot

def parent(par,x):
    if(par[x]==x):
        return x
    ans = parent(par,par[x])
    par[x]=ans
    return ans

def solve(n,f):
    par = [i for i in xrange(n)]
    oncyc=[]
    for i in xrange(n):
        #print i,f[i],parent(par,i),parent(par,f[i])
        if parent(par,i)==parent(par,f[i]):
            oncyc.append(i)
        par[parent(par,i)]=parent(par,f[i]) 
    for i in xrange(n):
        pass
        #print parent(par,i)
    ind = [0 for i in f]
    for i in f:
        ind[i]+=1
    shapes = {}
    cycley = [False for i in f]
    paths = [0 for i in f]

    for i in oncyc:
        #print i
        cycle = cyc(cycley,f,i)
        shapes[parent(par,i)]=(cycle,i)
    best = max(shapes[i][0] for i in shapes)
    other = 0
    for i in xrange(n):
        if ind[i]==0:
            lp = 1
            at=i
            while(not cycley[f[at]]):
                at=f[at]
                lp+=1
            paths[f[at]]=max(paths[f[at]],lp)
    for i in shapes:
        if(shapes[i][0]==2):
            a=shapes[i][1]
            b=f[a]
            other+=2+paths[a]+paths[b]
    return max(best,other)

t = int(raw_input())
for cas in xrange(1,t+1):
    n=int(raw_input())
    f = map(lambda x:int(x)-1,raw_input().split())
    ans=solve(n,f)
    print "Case #{}: {}".format(cas,ans)
