H,W,K=list(map(int,input().split()))

r = 10**9 + 7

dp=[[0 for i in range(W)] for j in range(H+1)]

dp[0][0]=1

num = [1,1,2,3,5,8,13,21]

if W!=1:
    for i in range(H):
        for j in range(W):
            if j==0:
                dp[i+1][j]=(num[W-1]*dp[i][j]+num[W-2]*dp[i][j+1])%r
            elif j==W-1:
                dp[i+1][j]=(num[W-1]*dp[i][j]+num[W-2]*dp[i][j-1])%r
            else:
                dp[i+1][j]=(num[j]*num[W-j-1]*dp[i][j]+num[j-1]*num[W-j-1]*dp[i][j-1]+num[j]*num[W-j-2]*dp[i][j+1])%r
    print(dp[H][K-1])
else:
    print(1)