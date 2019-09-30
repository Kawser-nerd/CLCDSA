from itertools import accumulate
n,k=map(int, input().split())
a=list(map(int,[input() for _ in range(n)]))
Sa=list(accumulate(a))
dp=[[float('inf')]*n for _ in range(n)]
if Sa[n-1]==k:
    print(1)
    exit()
if k==0:
    print(0)
elif n==1:
    print(1)
else:
    dp[0][0]=1
    for i in range(1,n):
        dp[i][0]=1
        for j in range(1,i+1):
            tmp=dp[i-1][j-1]*Sa[i]//Sa[i-1]+1
            dp[i][j]=min(tmp,dp[i-1][j])
    if dp[n-1][n-1]<=k:
        print(n)
    else:
        for i in range(n):
            if dp[n-1][i]<=k:
                ans=i+1
            else:
                print(ans)
                exit()