import sys
sys.setrecursionlimit(10**6)
n = int(input())
a = list(map(int,input().split()))
g = [[]for i in range(n)]
for i in range(n-1):
  x,y = map(int,input().split())
  x-=1;y-=1
  g[x].append(y)
  g[y].append(x)
used = [0]*n
ue = [0]*n
for i in range(n):
  if len(g[i])== 1:
    ne = i
    break
huka = [0]*n
def dfs(x,y,z):
  if used[x]:
    return 0
  used[x] = 1
  huka[x] = y
  ue[x] = z
  for ix in g[x]:
    dfs(ix,y+1,x)
dfs(ne,0,-1)
for i in range(n):
  huka[i] = [huka[i],i]
huka.sort(key=lambda x:-x[0])
hen = [0]*(n)
for i in range(n-1):
  x = huka[i][1]
  if len(g[x]) == 1:
    hen[x] = a[x]
    hen[ue[x]] += hen[x]
    if hen[x] > a[ue[x]]:
      print("NO")
      exit()
    continue
  hen[x] = a[x]*2-hen[x]
  hen[ue[x]] += hen[x]
  if hen[x] > a[ue[x]] or hen[x]>a[x]:
    print("NO")
    exit()
  if hen[x] <0:
    print("NO")
    exit()
if hen[ne] != a[ne]:
  print("NO")
else:
  print("YES")