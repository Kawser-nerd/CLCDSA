n,*a=map(int,open(0).read().split())
dp=[0 for i in range(n)]
dp[1]=abs(a[0]-a[1])
for i in range(2,n):
    x=abs(a[i]-a[i-2])+dp[i-2]
    y=abs(a[i]-a[i-1])+dp[i-1]
    #print(x,y)
    dp[i]=min(x,y)
print(dp[-1])