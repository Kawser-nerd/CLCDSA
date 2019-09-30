from collections import deque
N,M=map(int,input().split())
s=input()
H=[[] for i in range(N)]
G=[[] for i in range(2*N)]
for i in range(M):
    a,b=map(int,input().split())
    a-=1
    b-=1
    H[a].append(b)
    H[b].append(a)
    if s[a]=="A":
        if s[b]=="A":
            G[a].append(N+b)
            G[b].append(N+a)
        else:
            G[a+N].append(b+N)
            G[b].append(a)
    else:
        if s[b]=="A":
            G[a].append(b)
            G[N+b].append(N+a)
        else:
            G[N+a].append(b)
            G[N+b].append(a)
K=[0 for i in range(2*N)]
for i in range(2*N):
    for p in G[i]:
        K[p]+=1
q=deque(i for i in range(2*N) if K[i]==0)
res=[]
while q:
    v1=q.popleft()
    res.append(v1)
    for v2 in G[v1]:
        K[v2]-=1
        if K[v2]==0:
            q.append(v2)
if len(res)==2*N:
    print("No")
else:
    print("Yes")