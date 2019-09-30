N = int(input())
K = int(input())

mod = 10**9+7


def cmb(N, K, MOD):
    factorial = [1] * (N + K)
    for k in range(1, N + K - 1):
        factorial[k + 1] = (factorial[k] * (k + 1)) % MOD

    fact_inv = [1] * (N + K)
    fact_inv[N + K - 1] = pow(factorial[N + K - 1], MOD - 2, MOD)
    for k in range(N + K - 1, 0, -1):
        fact_inv[k - 1] = (fact_inv[k] * k) % MOD

    if N < 0 or K < 0 or N < K:
        return 0
    else:
        return (factorial[N] * fact_inv[K] * fact_inv[N - K]) % MOD


print(cmb(N+K-1, K, mod))