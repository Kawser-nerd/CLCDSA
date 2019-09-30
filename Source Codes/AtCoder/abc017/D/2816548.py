n, m = map(int, input().split())
f = [int(input())-1 for _ in range(n)]

MOD = 10**9+7

dp = [0]*(n+1)
dp[0] = 1

k = [False]*m
L = [0]*n

r = 0
for l in range(n):
    while r < n and not k[f[r]]:
        k[f[r]] = True
        L[r] += l
        r += 1
    if l == r:
        r += 1
    else:
        k[f[l]] = False
"""
print(k)
print(f)
print(L)
"""
s = 0
r = 0
for i in range(n):
    s = (s + dp[i]) % MOD
    while r < L[i]:
        s = (s - dp[r]) % MOD
        r += 1
    dp[i+1] = s % MOD

print(dp[-1])