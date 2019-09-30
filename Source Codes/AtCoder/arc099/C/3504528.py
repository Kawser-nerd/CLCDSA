import sys
sys.setrecursionlimit(10**7)
n,m = map(int,input().split())
G = [[1]*n for i in range(n)]
for i in range(m):
  a,b = map(int,input().split())
  a -=1;b-=1
  G[a][b] = G[b][a] = 0
colors = [-1 for i in range(n)]
possible = True
ni = []
def dfs(x,y):
  colors[x] = y
  k[y] += 1
  for l in range(n):
    if l == x or G[x][l] == 0:
      continue
    if colors[l] == -1:
      dfs(l,1-y)
    elif colors[l] != 1-y:
      global possible
      possible = False
for i in range(n):
  k = [0,0]
  if colors[i] != -1:
    continue
  dfs(i,0)
  ni.append([k[0],k[1]])
if possible == False:
  print(-1)
  exit()
dp =[0]*701
dp[0] = 1
for i in ni:
  for j in range(700,-1,-1):
    if dp[j]:
      dp[j] = 0
      dp[j+i[0]] = 1
      dp[j+i[1]] = 1
ans = float("inf")
for i in range(0,701):
  if dp[i]:
    tmp = (n-i)*(n-i-1)//2 + i*(i-1)//2
    ans = min(tmp,ans)
print(ans)