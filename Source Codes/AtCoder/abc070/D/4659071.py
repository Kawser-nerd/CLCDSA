import sys
sys.setrecursionlimit(10**6)
n = int(input())
inf = float("inf")
road = [dict() for _ in range(n+1)]
for _ in range(n-1):
  a,b,c = map(int, input().split())
  road[a][b] = c
  road[b][a] = c
q,k = map(int, input().split())
dfs = [inf]*(n+1)
dfs[k] = 0
def dodfs(x):
  for i in road[x]:
    if dfs[i] == inf:
      dfs[i] = dfs[x] + road[x][i]
      dodfs(i)
  return   
dodfs(k)
for _ in range(q):
  x,y = map(int, input().split())
  print(dfs[x] + dfs[y])