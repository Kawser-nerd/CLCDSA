from scipy.sparse.csgraph import floyd_warshall
n,m = map(int,input().split())
d = [[float("inf")]*n for i in range(n)]
L = []
for i in range(n):
    d[i][i] = 0
for i in range(m):
    a,b,l = map(int,input().split())
    if a == 1:
        L.append([a,b,l])
    else:
        d[a-1][b-1] = l
        d[b-1][a-1] = l
d = floyd_warshall(d)
ans = float('inf')
for i in range(len(L)-1):
    for j in range(i+1,len(L)):
        ans = min(ans,L[i][2]+L[j][2]+d[L[i][1]-1][L[j][1]-1])
if ans == float('inf'):
  print(-1)
else:
  print(int(ans))