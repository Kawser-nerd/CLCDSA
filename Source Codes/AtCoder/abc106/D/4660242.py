n,m,q = map(int,input().split())
dist = [list(map(int,input().split())) for i in range(m)]
query = [list(map(int,input().split())) for i in range(q)]

coord = [[0]*(n+1) for i in range(n+1)]

for i in range(m):
  coord[dist[i][0]][dist[i][1]] += 1

ruiseki = [[0]*(n+1) for i in range(n+1)]
for i in range(1,n+1):
  for j in range(1,n+1):
    ruiseki[i][j] = coord[i][j] + ruiseki[i-1][j]
 
for i in range(1,n+1):
  for j in range(1,n+1):
    ruiseki[i][j] = ruiseki[i][j]+ ruiseki[i][j-1]
#print(ruiseki)

for i,j in query:
  ans = ruiseki[j][j]-ruiseki[i-1][j]-ruiseki[j][i-1]+ruiseki[i-1][i-1]
  print(ans)