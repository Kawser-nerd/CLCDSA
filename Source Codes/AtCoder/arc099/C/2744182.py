from collections import deque
import sys
from operator import itemgetter
N,M = map(int,input().split())
table=[[1]*N for i in range(N)]
for i in range(N):
    table[i][i]=0
for i in range(M):
    a,b=map(int,input().split())
    table[a-1][b-1]=0
    table[b-1][a-1]=0
visit=[False]*N
color =[-1]*N
def f(i):
    q=deque()
    q.append(i)
    color[i]=0
    visit[i]=True
    r=[0,0]
    r[0]+=1
    while q:
        x= q.popleft()
        for j in range(N):
            if table[x][j]==0:
                continue
            if visit[j]:
                if (color[x]==color[j]):
                    print(-1)
                    sys.exit()
                continue
            q.append(j)
            color[j]=(color[x]+1)%2
            r[color[j]]+=1
            visit[j]=True
    return r
ans=[]
for i in range(N):
    if not visit[i]:
        ans.append(f(i))
r=sorted(ans,reverse=True)
#r=sorted(ans,reverse=True,key = itemgetter(1))
for i in range(1,len(ans)):
    if r[0][0]>r[0][1]:
        r[0][0]+=min(r[i][0],r[i][1])
        r[0][1]+=max(r[i][0],r[i][1])
    else:
        r[0][0]+=max(r[i][0],r[i][1])
        r[0][1]+=min(r[i][0],r[i][1])
def dou(k):
    return (k*(k-1))//2
print(dou(r[0][0]) + dou(r[0][1]))