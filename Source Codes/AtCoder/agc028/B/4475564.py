N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7

F = 1
for i in range(2, N + 1):
	F = F * i % mod

D = [0]
for i in range(2, N + 1):
	D.append(D[-1] + pow(i, mod - 2, mod))

L = [0] * N
for i in range(N // 2 + N % 2):
  t = round(F * (D[-1 - i] + D[i] + 1)) % mod
  L[i] = t
  L[-1 - i] = t

Ans = 0
for i in range(N):
  Ans += L[i] * A[i] % mod

print(Ans % mod)