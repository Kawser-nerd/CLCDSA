import math as ma
l = list(map(int,input().split()))
N = int(input())
N *= 4
dp = [0 for i in range(9)]
for i in range(1,9):
    dp[i] = min([dp[i-2**j]+l[j] for j in range(min(4,int(ma.log2(i)+1)))])
ans = float('inf')
for i in range(1,9):
    ans = min(ans,N//i*dp[i] + dp[N-N//i*i])
print(ans)