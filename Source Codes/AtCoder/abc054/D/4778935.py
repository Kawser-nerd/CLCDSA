N,Ma,Mb=list(map(int, input().strip().split()))
abc=[list(map(int, input().strip().split())) for i in range(N)]
maxW=N*10
dp=[{} for __ in range(N+1)]
dp[0][(0,0)]=0
for i in range(N):
    a,b,c=abc[i]
    for k,v in dp[i].items():
        dp[i+1][k]=min(dp[i][k], dp[i+1][k]if k in dp[i+1] else float("inf"))
        dp[i+1][k[0]+a,k[1]+b]=min(dp[i][k]+c, dp[i+1][k[0]+a,k[1]+b] if (k[0]+a,k[1]+b)in dp[i+1] else float("inf"))

cost=float("inf")
Mad=Ma
Mbd=Mb
while Ma<=maxW and Mb <=maxW:
    if (Ma,Mb) in dp[-1]:
        cost=min(dp[-1][Ma,Mb],cost)
    Ma+=Mad
    Mb+=Mbd
print(-1 if cost==float("inf") else cost)