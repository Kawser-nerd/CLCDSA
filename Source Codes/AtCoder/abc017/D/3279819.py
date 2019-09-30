n,m=map(int,input().split())
f=[int(input()) for _ in range(n)]
dp=[0 for _ in range(n+1)]
dp[0],dp[1]=1,1
x=[0 for i in range(m)]
x[f[0]-1]=1
sums=[0 for _ in range(n+1)]
sums[0],sums[1]=1,2
mod=1000000007
left=0
for i in range(1,n):
    left=max(left,x[f[i]-1])
    if left==0:
        dp[i+1]=(dp[i]*2)%mod
        sums[i+1]=(sums[i]+dp[i+1])%mod
        x[f[i]-1]=i+1
    else:
        dp[i+1]=(sums[i]-sums[left-1])%mod
        sums[i+1]=(sums[i]+dp[i+1])%mod
        x[f[i]-1]=i+1
print(dp[-1]%mod)