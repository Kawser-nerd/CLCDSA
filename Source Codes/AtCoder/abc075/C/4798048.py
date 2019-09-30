import sys
n,m=map(int,input().split())
vertex=[[int(i) for i in l.split()] for l in sys.stdin]
def find(x):
  if root[x]==x:
    return x
  root[x]=find(root[x])
  return root[x]
def check(x,y):
  return find(x)==find(y)
def union(x,y):
  x=find(x)
  y=find(y)
  if size[x]>=size[y]:
    root[y]=x
  else:
    root[x]=y
  if size[x]==size[y]:
    size[x]+=1
ans=0
for i in range(m):
  root=[i for i in range(n+1)]
  size=[0]*(n+1)
  for j in range(m):
    if j!=i:
      if check(vertex[j][0],vertex[j][1]):
        pass
      else:
        union(vertex[j][0],vertex[j][1])
  for j in range(1,n):
    if check(j,j+1)==True:
      pass
    else:
      ans+=1
      break
print(ans)