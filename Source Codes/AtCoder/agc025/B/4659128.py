class comb():
  F = [1, 1]
  Fi = [1, 1]
  I = [0, 1]
  def __init__(self, num, mod):
    self.MOD = mod
    for i in range(2, N + 1):
      self.F.append((self.F[-1] * i) % mod)
      self.I.append(mod - self.I[mod % i] * (mod // i) % mod)
      self.Fi.append(self.Fi[-1] * self.I[i] % mod)
  def com(self, n, k):
    if n < k: return 0
    if n < 0 or k < 0: return 0
    return self.F[n] * (self.Fi[k] * self.Fi[n - k] % self.MOD) % self.MOD

N, A, B, K = list(map(int, input().split()))
MOD = 998244353
com = comb(N, MOD)

if A > B:
  A, B = (B, A)
Rk = min(N, K // A)

Ans = 0
for i in range(Rk + 1):
  R = i
  if (K - (A * R)) % B != 0:
    continue
  C = (K - (A * R)) // B
  if C > N:
    continue
  Rc = com.com(N, R)
  Cc = com.com(N, C)
  Ans += (Rc * Cc) % MOD

print(Ans % MOD)