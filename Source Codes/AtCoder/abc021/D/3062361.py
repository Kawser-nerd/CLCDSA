def factorial_memo(n, p):
  F = [1] * (n + 1)
  for i in range(n):
    F[i + 1] = F[i] * (i + 1) % p
  return F

def inverse(F, p):
  Finv = [x for x in F]
  Finv[-1] = pow(Finv[-1], p - 2, p)
  for i in range(len(F) - 2, 0, -1):
    Finv[i] = Finv[i + 1] * (i + 1) % p
  return Finv

def comb(a, b):
  return F[a + b] * Finv[a] * Finv[b] % p

n = int(input())
k = int(input())
p = 10 ** 9 + 7
F = factorial_memo(n + k - 1, p)
Finv = inverse(F, p)
print(comb(n - 1, k))