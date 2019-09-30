import sys
sys.setrecursionlimit(1000000)
I=lambda:map(int,input().split())
n,m=I()
g=[set() for _ in range(n+1)]
v=[1 for _ in range(n+1)]
v[1]=0

for _ in range(m):
  a,b=I()
  g[a].add(b)
  g[b].add(a)

def dfs(x):
  for j in g[x]:
    if v[j]:
      v[j]=0
      l=dfs(j)
      l.append(j)
      return l
      break
  else:
    return []
z=dfs(1)+[1]+dfs(1)[::-1]
print(len(z))
print(*z)