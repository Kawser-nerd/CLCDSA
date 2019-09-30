n,m = map(int,input().split())

tree = [[] for i in range(n)]
kyori = [[float("inf")]*n for i in range(n)]
for i in range(m):
  tmp1,tmp2 = map(int,input().split())
  tree[tmp1-1].append(tmp2-1)
  tree[tmp2-1].append(tmp1-1)
  kyori[tmp1-1][tmp2-1]=1
  kyori[tmp2-1][tmp1-1]=1

for i in range(n):
  kyori[i][i]=0

for k in range(n):
  for i in range(n):
    for j in range(n):
      kyori[i][j] = min(kyori[i][j],kyori[i][k]+kyori[k][j])

ans = 0
for i in range(n):
  ans = 0
  for j in range(n):
    if kyori[i][j]==2:
      ans = ans +1
  print(ans)