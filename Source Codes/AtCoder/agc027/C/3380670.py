import sys
from collections import deque
N,M=map(int,input().split())
s=input()
table=[]
for i in range(M):
    x,y=map(int,input().split())
    table.append((x-1,y-1))
edge=[[]for i in range(2*N)]
visit=[0]*(2*N)
for x,y in table:
    if x==y:
        edge[2*x].append(2*x+1)
        visit[2*x+1]+=1
        continue
    if s[x]==s[y]:
        edge[2*x].append(2*y+1)
        edge[2*y].append(2*x+1)
        visit[2*x+1]+=1
        visit[2*y+1]+=1
        continue
    edge[2*x+1].append(2*y)
    edge[2*y+1].append(2*x)
    visit[2*x]+=1
    visit[2*y]+=1
S=set()
L=deque()

for i in range(2*N):
    if visit[i]==0:
        L.append(i)

while L:
    x=L.pop()
    S.add(x)
    for y in edge[x]:
        visit[y]-=1
        if visit[y]==0:
            L.append(y)
if len(S)!=2*N:
    print('Yes')
else:
    print('No')