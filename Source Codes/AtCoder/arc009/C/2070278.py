N, K = map(int, input().split())
MOD = 1777777777
# C(N, K)
N %= MOD
r = 1
for i in range(1, K+1):
    r = (r * i) % MOD
ans = pow(r, MOD-2, MOD)
for i in range(K):
    ans *= (N-i)
    ans %= MOD

# ??????: a_K
a = 0; b = 1 # a_1 = 0, a_2 = 1
for i in range(2, K):
    a, b = b, i*(a + b) % MOD
ans *= b
ans %= MOD

# ans = C(N, K) * a_K
print(ans)