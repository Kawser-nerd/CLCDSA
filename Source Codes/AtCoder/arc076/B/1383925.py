N = int(input())


class DisjointSet:
  def __init__(self, size):
    self.parent = list(range(size))
    self.rank = [0]*size
  
  def find(self, x):
    if self.parent[x] == x:
      return x
    else:
      self.parent[x] = self.find(self.parent[x])
      return self.parent[x]

  def union(self, x, y):
    xr = self.find(x)
    yr = self.find(y)
    if self.rank[xr] > self.rank[yr]:
      self.parent[yr] = xr
    elif self.rank[xr] < self.rank[yr]:
      self.parent[xr] = yr
    elif xr != yr:
      self.parent[yr] = xr
      self.rank[xr] += 1


X,Y = [],[]
for i in range(N):
  x,y = map(int, input().split())
  X.append((x,i))
  Y.append((y,i))

X.sort()
Y.sort()

def convert_to_dists(L):
  it = iter(L)
  it2 = iter(L)
  next(it2)

  D = []

  for a,b in zip(it, it2):
    ax, ai = a
    bx, bi = b
    d = abs(ax-bx)
    D.append((d,ai,bi))
  return D

dX = convert_to_dists(X)
dY = convert_to_dists(Y)

D = dX+dY
D.sort()

cost = 0
S = DisjointSet(N)
edge_count = 1

for d,i,j in D:
  if S.find(i) != S.find(j):
    S.union(i,j)
    cost += d
    edge_count += 1
    if edge_count >= N:
      break

print(cost)