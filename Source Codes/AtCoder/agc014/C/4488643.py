import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque
from math import ceil

h,w,k=map(int,input().split())
MAP=[]
for i in range(h):
    s=list(input().strip())
    for j,t in enumerate(s):
        if t=='S':
            sx,sy=i,j
    MAP.append(s)
delta=[[1,0],[0,1],[-1,0],[0,-1]]
q=deque()
q.append((sx,sy,k))
dist=float('inf')
Visited=[[False]*w for _ in range(h)]
Visited[sx][sy]=True
while q:
    x,y,t=q.popleft()
    dist=min(dist,x,y,h-1-x,w-1-y)
    if not dist:
        break
    if t:
        t-=1
        for dx,dy in delta:
            if MAP[x+dx][y+dy]=='.' and not Visited[x+dx][y+dy]:
                q.append((x+dx,y+dy,t))
                Visited[x+dx][y+dy]=True
print(1+ceil(dist/k))