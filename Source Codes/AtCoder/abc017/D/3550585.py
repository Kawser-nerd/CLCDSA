N, M = map(int, input().split())
F = [0] * N
MOD = 10 ** 9 + 7
for i in range(N):
    f = int(input())
    F[i] = f

dp = [0] * (N + 1)
rec = [0] * (M + 1)
dp[0] = 1
s = dp[0]
l = 0
for i in range(N):
    rec[F[i]] += 1
    while rec[F[i]] > 1:
        rec[F[l]] -= 1
        s -= dp[l]
        s += MOD
        s %= MOD
        l += 1
    dp[i + 1] = s
    s += dp[i + 1]
    s %= MOD

print(dp[N])