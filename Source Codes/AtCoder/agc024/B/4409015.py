N = int(input())
P = [int(input()) for i in range(N)]


Q = sorted([(p, i) for i, p in enumerate(P, start=1)])
Q = [i for p, i in Q]

dp = [1] * (N + 1)
for i in range(1, N):
    if Q[i] > Q[i - 1]:
        dp[i] = dp[i - 1] + 1

print(N - max(dp))