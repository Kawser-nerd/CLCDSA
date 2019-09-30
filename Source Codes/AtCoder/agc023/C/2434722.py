N = int(input())
MOD = 10**9 + 7

fact = [1]*(N+1)

for i in range(1, N+1):
    fact[i] = r = i*fact[i-1] % MOD

cnts = [0]*(N+1)
rev = 1
for K in range(N-1, (N+1)//2-1, -1):
    cnts[K] = fact[K]*fact[K-1]*rev % MOD
    rev = rev * (2*K-N) * (2*K-N-1) % MOD

ans = 0
for K in range((N+1)//2, N):
    ans += (cnts[K] - cnts[K-1]) * K % MOD
    ans %= MOD
ans = (ans * pow(fact[N-2], MOD-2, MOD)) % MOD
print(ans)