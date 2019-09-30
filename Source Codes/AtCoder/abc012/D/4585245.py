from scipy.sparse.csgraph import floyd_warshall
n,m = map(int,input().split())
d = [[float("inf")]*n for i in range(n)]
for i in range(n):
    d[i][i] = 0
for i in range(m):
    a,b,l = map(int,input().split())
    d[a-1][b-1] = l
    d[b-1][a-1] = l
d = floyd_warshall(d)
toomawari = float('inf')
for i in range(n):
  cur = max(d[i])
  if toomawari > cur:
    toomawari = cur
print(int(toomawari))