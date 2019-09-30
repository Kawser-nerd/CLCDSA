N,M,R=map(int,input().split())
X=list(map(int,input().split()))
from collections import defaultdict
from collections import deque
branch=defaultdict(set)
for m in range(M):
    a,b,c=map(int,input().split())
    branch[a]|={(b,c)}
    branch[b]|={(a,c)}
def makedist(x):
    dist=[float('inf')]*(N+1)
    dist[x]=0
    check={x,}
    while len(check)>0:
        now=check.pop()
        for b in branch[now]:
            if dist[now]+b[1]<dist[b[0]]:
                dist[b[0]]=dist[now]+b[1]
                check|={b[0],}
    return dist
data=dict()
for x in X:
    data[x]=makedist(x)
def roop(now,D,notvisit,ans):
    if len(notvisit)==0:
        return min(D,ans)
    for nex in notvisit:
        ans=roop(nex,D+data[now][nex],notvisit-{nex,},ans)
    return ans
ans=float('inf')
for x in X:
    ans=min(ans,roop(x,0,set(X),float('inf')))
print(ans)