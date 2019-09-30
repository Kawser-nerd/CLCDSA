from collections import deque
N=int(input())
G=[[] for i in range(N)]
for i in range(N-1):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
q=deque([0])
P=[-2 for i in range(N)]
P[0]=-1
while(q):
    r=q.popleft()
    for p in G[r]:
        if P[p]==-2:
            P[p]=r
            q.append(p)
H=[[] for i in range(N)]
for i in range(1,N):
    H[P[i]].append(i)
mod=10**9+7
W=[0 for i in range(N)]
B=[0 for i in range(N)]
def white(i):
    if W[i]!=0:
        return W[i]
    if len(H[i])==0:
        W[i]=1
        return 1
    res=1
    for j in H[i]:
        res=res*(black(j)+white(j))
        res%=mod
    W[i]=res
    return res
def black(i):
    if B[i]!=0:
        return B[i]
    if len(H[i])==0:
        B[i]=1
        return 1
    res=1
    for j in H[i]:
        res=res*white(j)
        res%=mod
    B[i]=res
    return res
print((black(0)+white(0))%mod)