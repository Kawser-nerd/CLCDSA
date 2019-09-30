n = int(input())
c = [0] + [int(input()) for _ in range(n)]
dp = [0] * (200001)
num = 1
for i in range(n):
    if c[i]!=c[i+1]:
        num += dp[c[i+1]]
        dp[c[i+1]] = num
print(num%(10**9+7))