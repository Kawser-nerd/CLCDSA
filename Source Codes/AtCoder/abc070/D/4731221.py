N=int(input())
from collections import defaultdict
from collections import deque
branch=defaultdict(set)
for i in range(N-1):
    a,b,c=map(int,input().split())
    branch[a]|={(b,c),}
    branch[b]|={(a,c),}
Q,K=map(int,input().split())
dist=[float('inf')]*(N+1)
dist[K]=0
check=deque([K])
while len(check)>0:
    now=check.popleft()
    for nex,c in branch[now]:
        if dist[nex]>dist[now]+c:
            dist[nex]=dist[now]+c
            check.append(nex)
for q in range(Q):
    x,y=map(int,input().split())
    print(dist[x]+dist[y])