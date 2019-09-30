N=int(input())
now=0
T=list(map(int,input().split()))
for i in range(1,N):
    T[i]+=T[i-1]
T=[-1*float('inf'),0]+T+[float('inf')]
V=list(map(int,input().split()))
V=[0]+V+[0]
vt=[float('inf')]*(T[-2]+1)
for t in range(len(vt)):
    now=t
    for k in range(N+2):
        if now<T[k]:
            vt[t]=min(vt[t],V[k]+T[k]-now)
        elif T[k]<=now<=T[k+1]:
            vt[t]=min(vt[t],V[k])
        elif T[k+1]<now:
            vt[t]=min(vt[t],V[k]+now-T[k+1])
ans=0
for i in range(len(vt)-1):
    if abs(vt[i+1]-vt[i])==1:
        ans+=0.5*(vt[i]+vt[i+1])
    elif vt[i+1]==vt[i]:
        for k in range(N+2):
            if T[k]<=i and i+1<=T[k+1]:
                vv=V[k]
                break
        if vv>vt[i]:
            ans+=0.5*(vt[i]*2+0.5)
        else:
            ans+=vt[i]
print(ans)