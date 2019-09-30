from collections import deque
N,M=map(int,input().split())
G=[set() for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    a-=1;b-=1;G[a].add(b);G[b].add(a)
q=deque([]);q.append(0)
used=[0 for i in range(N)];used[0]=1
while(True):
    flag=0
    a=q[0]
    for p in G[a]:
        if used[p]==0:
            q.appendleft(p)
            used[p]=1
            flag=1
            break
    b=q[-1]
    for p in G[b]:
        if used[p]==0:
            q.append(p)
            used[p]=1
            flag=1
            break
    if flag==0:
        break
ans=[str(i+1) for i in q]
print(len(ans))
print(" ".join(ans))