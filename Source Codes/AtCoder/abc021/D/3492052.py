N = int(input())
K = int(input())
M = (10 ** 5) * 2 + 1
MOD = 10 ** 9 + 7
fact = [0] * M
rfact = [0] * M
fact[0] = 1
for i in range(1, M):
    fact[i] = fact[i - 1] * i % MOD

rfact[M - 1] = pow(fact[M - 1], MOD - 2, MOD)
for i in range(M - 2, -1, -1):
    rfact[i] = (rfact[i + 1] * (i + 1)) % MOD

print(fact[N + K - 1] * rfact[K] * rfact[N - 1] % MOD)