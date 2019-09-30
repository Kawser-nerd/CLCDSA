import sys
sys.setrecursionlimit(200000)
n,k = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
if a[0] != 1:
  a[0] = 1
  ans += 1
b = [[]for i in range(n)]
for i in range(1,n):
  b[a[i]-1].append(i)
huka = 0
kyo = [float("inf")] * n
z =[[]for i in range(n)]
def dfs(x,y):
  kyo[x] = y
  z[y].append(x)
  for i in b[x]:
    dfs(i,y+1)
dfs(0,0)
def dfs2(x,y):
  if kyo[x] <=k-y:
    return
  if y == k-1 and x != 0:
    kyo[x] = 0
    global ans
    ans += 1
    return
  kyo[x] = 0
  dfs2(a[x]-1,y+1)
for i in range(n-1,k,-1):
  for j in z[i]:
    dfs2(j,0)
print(ans)