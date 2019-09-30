n, x = map(int, input().split())
p = n
if x * 2 > n:
  x = n - x
ans = 0
while(x > 0):
  if n == p:
    ans += 3 * x * (n // x - 1)
  else:
    ans += 3 * x * (n // x)
  n, x = x, n % x
print(ans)