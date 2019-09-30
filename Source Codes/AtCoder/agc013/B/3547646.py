from collections import deque
N,M=map(int,input().split())
G=[[] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
X=[0 for i in range(N)]
q=deque([])
q.append(0)
q.append(G[0][0])
X[0]=1
X[G[0][0]]=1
while(True):
    r=q[0]
    flag=0
    for p in G[r]:
        if X[p]==0:
            q.appendleft(p)
            X[p]=1
            flag=1
            break
    if flag==1:
        continue
    r=q[-1]
    flag=0
    for p in G[r]:
        if X[p]==0:
            q.append(p)
            X[p]=1
            flag=1
            break
    if flag==0:
        break
L=[str(i+1) for i in q]
print(len(L))
print(" ".join(L))