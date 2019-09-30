N,M = map(int,input().split())
P = list(map(int,input().split()))
L = []
for i in range(M):
  L.append(list(map(int,input().split())))
par = []
rank = []
for i in range(N):
  par.append(i)
  rank.append(0)
def find(x,par):
  if par[x] == x:
    return x
  else:
    return find(par[x],par)
def unite(x,y,par,rank):
  x = find(x,par)
  y = find(y,par)
  if x != y:
    if rank[x] < rank[y]:
      par[x] = y
    else:
      par[y] = x
      if rank[x] == rank[y]:
        rank[x] += 1
for i in range(M):
  unite(L[i][0]-1,L[i][1]-1,par,rank)
ans = 0
for i in range(N):
  if find(P[i]-1,par) == find(i,par):
    ans += 1
print(ans)