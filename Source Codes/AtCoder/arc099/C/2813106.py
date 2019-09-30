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
#print(ans)
dp=[set() for i in range(len(ans)+1)]
dp[0].add(0)
L=N//2+1
for i in range(1,len(ans)+1):
    for a in dp[i-1]:
        if a+ans[i-1][0]<L:
            dp[i].add(a+ans[i-1][0])
        if a+ans[i-1][1]<L:
            dp[i].add(a+ans[i-1][1])
    #print(dp)
s = max(dp[len(ans)])
def dou(k):
    return (k*(k-1))//2
print(dou(s) + dou(N-s))