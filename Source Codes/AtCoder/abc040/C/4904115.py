n=int(input())

X=list(map(int,input().split()))

dp=[0]*n

dp[0]=0
dp[1]=abs(X[1]-X[0])


for i in range(2,n):
    dp[i]=min(dp[i-1]+abs(X[i]-X[i-1]),dp[i-2]+abs(X[i]-X[i-2]))

print(dp[n-1])