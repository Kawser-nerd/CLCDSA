n=int(input())
edges=[[0]*n for i in range(n)]
for i in range(n-1):
  b=int(input())
  edges[b-1][i+1]=1

def dfs(u):
  if 1 not in edges[u]:
    return 1
  else:
    ls=[]
    for v in range(len(edges[u])):
      if edges[u][v]==1:
        ls.append(dfs(v))
  return max(ls)+min(ls)+1
print(dfs(0))