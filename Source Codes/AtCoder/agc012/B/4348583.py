from collections import deque
N,M=map(int,input().split())
G=[[] for i in range(N)]
for i in range(M):
    a,b=map(int,input().split())
    G[a-1].append(b-1)
    G[b-1].append(a-1)
Q=int(input())
v=[0 for i in range(Q)]
d=[0 for i in range(Q)]
c=[0 for i in range(Q)]
for i in range(Q):
    v[-i-1],d[-i-1],c[-i-1]=map(int,input().split());v[-i-1]-=1
q=deque()
color=[0 for i in range(N)]
dp=[-1 for i in range(N)]
for t in range(Q):
    if dp[v[t]]>=d[t]:
        continue
    dp[v[t]]=d[t]
    q.append((v[t],d[t]))
    while(q):
        vv,dd=q.popleft()
        if color[vv]==0:
            color[vv]=c[t]
        dd-=1
        for y in G[vv]:
            if dp[y]>=dd:
                continue
            dp[y]=dd
            q.append((y,dd))
for line in color:
    print(line)