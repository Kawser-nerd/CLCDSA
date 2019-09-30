n=int(input())
ng=list([int(input()) for i in range(3)])
dp=[float("inf")]*301
dp[n]=0
for i in range(n,-1,-1):
    if i in ng:
        continue
    for j in range(1,4):
        dp[i-j]=min(dp[i]+1,dp[i-j])
print("YES" if dp[0]<=100 else "NO")