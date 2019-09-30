import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque
n,m=map(int, input().split())
Edges=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int, input().split())
    Edges[a-1].append(b-1)
    Edges[b-1].append(a-1)
q=int(input())
Q=[list(map(int,input().split())) for _ in range(q)][::-1]
Visited=[-1]*n
Color=[0]*n
que=deque()
for v,d,c in Q:
    v-=1
    if Visited[v]>=d:
        continue
    Visited[v]=d
    que.append((v,d))
    while que:
        v,d=que.popleft()
        if not Color[v]:
            Color[v]=c
        d-=1
        for i in Edges[v]:
            if Visited[i]>=d:
                continue
            Visited[i]=d
            que.append((i,d))
print(*Color,sep="\n")