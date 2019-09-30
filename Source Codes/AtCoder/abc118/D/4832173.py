n,m= map(int,input().split())
A = list(map(int,input().split()))
cost = [0,2,5,5,4,5,6,3,7,6]
dp =[-1]*10010
dp[0]=0
for i in range(1,n+1):
    for a in A:
        if i - cost[a] >= 0:
            dp[i] = max(dp[i],a+dp[i-cost[a]]*10)
print(dp[n])