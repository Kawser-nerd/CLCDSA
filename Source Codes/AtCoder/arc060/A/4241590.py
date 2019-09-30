n,a=map(int,input().split())
x=list(map(int,input().split()))
p=max(max(x),a)
s=[i-a for i in x]
dp=[[0]*(2*n*p+1) for i in range(n+1)]
dp[0][n*p]=1
for i in range(1,n+1):
    for j in range(2*n*p+1):
        if j-s[i-1]<0 or j-s[i-1]>2*p*n:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=dp[i-1][j]+dp[i-1][j-s[i-1]]
print(dp[n][n*p]-1)