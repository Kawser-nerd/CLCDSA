import bisect

N = int(input())
A = [int(input()) for i in range(N)]
dp = [(2 * N) for _ in range(N)]
for i in range(N):
    s = bisect.bisect_left(dp, A[i])
    dp[s] = min(dp[s], A[i])
print(N - bisect.bisect_left(dp, 2 * N))