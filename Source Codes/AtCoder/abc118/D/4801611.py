N, M = map(int, input().split())
A = list(map(int, input().split()))
 
need = [0,2,5,5,4,5,6,3,7,6]
 
dp = [-1] * (N + 1)
dp[0] = 0
 
for i in range(N + 1):
        for a in A:
                if i + need[a] <= N:
                        dp[i + need[a]] = max(dp[i + need[a]], dp[i] * 10 + a)
 
print(dp[-1])