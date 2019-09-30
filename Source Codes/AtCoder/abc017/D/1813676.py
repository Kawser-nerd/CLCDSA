import sys

div = 10**9 + 7

N, M = map(int, sys.stdin.readline().split())

f = []
for n in range(N):
    f.append(int(sys.stdin.readline()))


# dp[i] := #{??? | i????????}
dp = [0] * (N+1)

dp[0] = 1

begin = 0
s = 0
taste_set = set()
for n in range(1, N+1):
    s += dp[n-1]
    if f[n-1] in taste_set:
        idx = f.index(f[n-1], begin, n-1)
        taste_set.difference_update(set(f[begin: idx+1]))
        s -= sum(dp[begin: idx + 1])
        begin = idx + 1
    taste_set.add(f[n-1])
    s %= div
    dp[n] = s

print(dp[N]% div)