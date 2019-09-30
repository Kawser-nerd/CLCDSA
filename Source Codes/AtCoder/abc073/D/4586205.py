from scipy.sparse.csgraph import floyd_warshall
import itertools
n,m,r = map(int,input().split())
L = list(map(int,input().split()))
d = [[float("inf")]*n for i in range(n)]
for i in range(n):
    d[i][i] = 0
for i in range(m):
    a,b,l = map(int,input().split())
    d[a-1][b-1] = l
    d[b-1][a-1] = l
d = floyd_warshall(d)
ans = float('inf')
seq = []
for i in range(r):
  seq.append(i)
K = list(itertools.permutations(seq))
for i in range(len(K)):
  cur = 0
  for j in range(1,r):
    p = L[K[i][j-1]]-1
    q = L[K[i][j]]-1
    cur += d[p][q]
  if cur != float('inf'):
    if cur <= ans:
      ans = cur
print(int(ans))