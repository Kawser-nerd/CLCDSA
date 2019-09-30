def congruence(x, y): #=(a, b) such that ax+by=gcd(x,y)
  if x < y:
    (a, b) = congruence(y, x)
    return (b, a)
  z = x % y
  if z == 0:
    return (0, 1)
  (c, d) = congruence(y, z)
  return (d, (c - int(x / y) * d) % 1000000007)

inverse_sum = {1: 1}
for i in range(2, 100001):
  inverse_sum[i] = (inverse_sum[i - 1] + congruence(1000000007, i)[1]) % 1000000007

N = int(input())
A = list(map(int, input().split()))

N_factorial = 1
for i in range(1, N + 1):
  N_factorial = (N_factorial * i) % 1000000007

ans = 0
for i in range(N):
  ans = (ans + (inverse_sum[i + 1] + inverse_sum[N - i] - 1) * A[i] * N_factorial) % 1000000007

print(ans)