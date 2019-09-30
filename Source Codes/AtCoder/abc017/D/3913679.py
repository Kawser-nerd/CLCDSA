import sys
input = sys.stdin.readline

n, m = map(int, input().split())
f = [int(input()) for _ in range(n)]

mod = 10**9 + 7

dp = [0] * (n+1)
cdp = [0] * (n+1)

s = set([f[0]])
l = 0
r = 1
dp[0] = 1
dp[1] = 1
cdp[0] = 1
cdp[1] = 2

while r < n:
    if f[r] in s:
        s.remove(f[l])
        l += 1
    else:
        s.add(f[r])
        if l > 0:
            dp[r + 1] = (cdp[r] - cdp[l - 1]) % mod
        else:
            dp[r + 1] = (cdp[r]) % mod
        cdp[r+1] = (dp[r+1] + cdp[r]) % mod
        r += 1

print(dp[n])