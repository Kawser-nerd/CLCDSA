from scipy.sparse.csgraph import floyd_warshall 
def solve():
  n,m  = (int(i) for i in input().split())
  distance = [[10**15]* n for _ in range(n)]
  L = []
  for i in range(n):
    distance[i][i] = 0
  for i in range(m):
    u,v,l = (int(i) for i in input().split())
    if u == 1:#???????????
     L.append([u,v,l])
    else:
      distance[u-1][v-1] = l
      distance[v-1][u-1] = l
    #print(distance)
    #print(L)
    
  d = floyd_warshall(distance)
  ans = 10**15
  for i in range(len(L)-1):
    for j in range(i+1,len(L)):
      ans = min(ans,L[i][2]+L[j][2]+d[L[i][1]-1][L[j][1]-1])
  if ans == 10**15:
   print("-1")
  else:
   print(int(ans))
solve()