N = int(input())
h_list = list(map(int, input().split(' ')))
dp = [10**9 for _ in range(N)]
dp[0] = 0
for i in range(1, N):
    dp[i] = min(dp[i], dp[i-1] + abs(h_list[i] - h_list[i-1]))
    if i > 1:
        dp[i] = min(dp[i], dp[i-2] + abs(h_list[i] - h_list[i-2]))
print(dp[-1])