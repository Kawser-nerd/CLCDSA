N=int(input())

A=list()

for i in range(2):
    A.append(list(map(int,input().split())))


dp = [[0 for i in range(N + 1)] for j in range(2)] 

dp[0][0]=A[0][0]
dp[1][0]=A[0][0]+A[1][0]

for j in range(N-1):
    dp[0][j+1]=dp[0][j]+A[0][j+1]

for j in range(N-1):
    dp[1][j+1]=max(dp[0][j+1]+A[1][j+1],dp[1][j]+A[1][j+1])


print(dp[1][N-1])