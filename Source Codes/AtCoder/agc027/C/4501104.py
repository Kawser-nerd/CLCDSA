import sys
input=sys.stdin.readline
sys.setrecursionlimit(10**9)
from collections import deque
n,m=map(int,input().split())
s=input()
A=[0]*n
B=[0]*n
Edges=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a-=1
    b-=1
    if a==b:
        if s[a]=='A':
            A[a]+=1
        else:
            B[a]+=1
    else:
        Edges[a].append(b)
        Edges[b].append(a)
        if s[a]=='A':
            A[b]+=1
        else:
            B[b]+=1
        if s[b]=='A':
            A[a]+=1
        else:
            B[a]+=1
Del=[False]*n
q=deque()
for i in range(n):
    if A[i]*B[i]==0:
        q.append(i)
        Del[i]=True
while q:
    u=q.pop()
    l=s[u]
    for v in Edges[u]:
        if Del[v]:
            continue
        if l=='A':
            A[v]-=1
        else:
            B[v]-=1
        if A[v]*B[v]==0:
            q.append(v)
            Del[v]=True
print('No' if sum(Del)==n else 'Yes')