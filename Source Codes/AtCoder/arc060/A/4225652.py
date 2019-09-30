def makelist2(n,m):
    return[[0 for k in range(m)]for i in range(n)]

n,a = map(int,input().split())
x = list(map(int,input().split()))
X = max(x)
X = max(X,a)
b=[]
for i in range(n):
    b.append(x[i]-a)


dp =makelist2(n+1,2*n*X+1)
dp[0][n*X] = 1
for j in range(n+1):
    for t in range(2*n*X+1):
        if j>=1 and (t-b[j-1] < 0 or t-b[j-1]>2*n*X):
            dp[j][t] = dp[j-1][t]
        elif j>= 1:
            dp[j][t] = dp[j-1][t] + dp[j-1][t-b[j-1]]
print(dp[n][n*X]-1)