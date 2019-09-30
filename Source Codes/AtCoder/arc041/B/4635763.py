n,m=map(int,input().split())
b=eval('list(map(int,input())),'*n)
a=eval('[0]*m,'*n)
for i in range(1,n-1):
 for j in range(1,m-1):a[i][j]=b[i-1][j]-a[i-1][j+1]-a[i-1][j-1]-a[i-2][j]
for i in a:print(*i,sep='')