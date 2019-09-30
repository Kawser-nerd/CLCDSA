n,a=map(int,input().split())
X=list(map(int,input().split()))

dp=[[[0]*(sum(X)+1) for _ in range(n+1)] for _ in range(n+1)]
dp[0][0][0]=1

for i in range(1,n+1): #x_1,x_2...x_n
  for k in range(i):   #k????
    for j in range(sum(X)+1): #??
      if dp[i-1][k][j]:
        dp[i][k+1][j+X[i-1]]+=dp[i-1][k][j]
        dp[i][k][j]+=dp[i-1][k][j]
ans=0
for i in range(1,n+1):
  for j in range(1,sum(X)+1):
    if j==i*a:
      ans+=dp[n][i][j]
print(ans)