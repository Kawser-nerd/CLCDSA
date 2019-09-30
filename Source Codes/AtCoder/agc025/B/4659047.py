N, A, B, K = list(map(int, input().split()))
MOD = 998244353

F = [1, 1]
Fi = [1, 1]
I = [0, 1]
for i in range(2, N + 1):
  F.append((F[-1] * i) % MOD)
  I.append(MOD - I[MOD % i] * (MOD // i) % MOD)
  Fi.append(Fi[-1] * I[i] % MOD)

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
  Rc = F[N] * (Fi[R] * Fi[N - R] % MOD) % MOD
  Cc = F[N] * (Fi[C] * Fi[N - C] % MOD) % MOD
  Ans += (Rc * Cc) % MOD

print(Ans % MOD)