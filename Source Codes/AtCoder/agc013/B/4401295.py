import sys
input=sys.stdin.readline
from collections import deque
n,m=map(int,input().split())
E=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    E[a].append(b)
    E[b].append(a)
q=deque([0])
Visited=[False]*n
Visited[0]=True
while True:
    s=q[0]
    for v in E[s]:
        if not Visited[v]:
            Visited[v]=True
            q.appendleft(v)
            break
    else:
        break
while True:
    g=q[-1]
    for v in E[g]:
        if not Visited[v]:
            Visited[v]=True
            q.append(v)
            break
    else:
        break
print(len(q))
print(*list(map(lambda x: x+1,q)))