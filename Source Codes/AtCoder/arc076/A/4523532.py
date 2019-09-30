def factorial(n):
  ans = 1
  for i in range(n):
    ans *= i+1
    ans %= mod
  return ans

n,m = map(int, input().split())
mod = 10**9 + 7
diff = abs(n-m)
if diff == 0:
  print((((factorial(n)**2)%mod)*2)%mod)
elif diff == 1:
  print((factorial(n)*factorial(m))%mod)
else:
  print(0)