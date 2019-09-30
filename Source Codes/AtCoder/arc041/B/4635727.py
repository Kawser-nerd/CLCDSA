n,m=map(int,input().split())
s=eval('list(map(int,input())),'*n)
a=eval('[0]*m,'*n)
for i in range(n-2):
  for j in range(1,m-1):
    a[i+1][j]=s[i][j]
    for x,y in((i+1,j-1),(i+2,j),(i+1,j+1),(i,j)):
      s[x][y]-=s[i][j]
for i in a:
  print(*i,sep='')