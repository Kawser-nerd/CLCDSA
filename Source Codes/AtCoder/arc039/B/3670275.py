N, K = map(int, input().split())
MOD = int(1e9+7)

M = N + K + 10
fac, finv, inv = [1]*M, [1]*M, [1]*M

# ??????????
def COMinit(MAX):
  fac[0], fac[1] = 1, 1
  finv[0], finv[1] = 1, 1
  inv[1] = 1
  for i in range(2,MAX):
    fac[i] = fac[i - 1] * i % MOD
    inv[i] = MOD - inv[MOD%i] * (MOD // i) % MOD
    finv[i] = finv[i - 1] * inv[i] % MOD

# ??????
def COM(n,k):
  if n < k or n < 0 or k < 0:
    return 0
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD

COMinit(M)  
  
if N > K:
  print(COM(N+K-1, N-1))
else:
  a = K%N
  print(COM(N,a))