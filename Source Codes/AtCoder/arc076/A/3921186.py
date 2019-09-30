MOD = int(1e9) + 7

n, m = map(int, input().split())

if abs(m - n) >= 2:
  ans = 0
else:
  ans = 1
  for i in range(1, m+1):
    ans *= i
    ans %= MOD
  for i in range(1, n+1):
    ans *= i
    ans %= MOD
  if n == m:
    ans = (ans * 2) % MOD

print(ans)