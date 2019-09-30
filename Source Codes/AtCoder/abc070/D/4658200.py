import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)
from collections import deque

N = int(input())
ad = [[] for _ in range(N)]
for _ in range(N-1):
    a,b,c = map(int,input().split())
    a -= 1; b -= 1
    ad[a].append((b,c))
    ad[b].append((a,c))

Q,K = map(int,input().split())
K -= 1
query = [[int(e)-1 for e in input().split()] for _ in range(Q)]
dis = [0]*N

def dfs(v=K,d=0,pv=-1):
    for nv,nd in ad[v]:
        if nv == pv:
            continue
        dis[nv] = d+nd
        dfs(nv,d+nd,v)

dfs()
for x,y in query:
    ans = dis[x] + dis[y]
    print(ans)