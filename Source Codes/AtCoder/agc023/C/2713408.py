def prepare(n, MOD):
    f = 1
    factorials = [1]
    for m in range(1, n + 1):
        f *= m
        f %= MOD
        factorials.append(f)
    inv = pow(f, MOD - 2, MOD)
    inverses = [1] * (n + 1)
    inverses[n] = inv
    for m in range(n, 1, -1):
        inv *= m
        inv %= MOD
        inverses[m - 1] = inv
    return factorials, inverses


def solve(n):
    MOD = 1000000007
    fac, inv = prepare(n, MOD)
    ans = 0
    cnt = 0
    for k in range((n + 1) // 2, n):
        tmp = fac[k - 1] * inv[n - 1 - k] * inv[2 * k - n]
        tmp %= MOD
        tmp *= fac[k]
        tmp %= MOD
        tmp *= fac[n - 1 - k]
        tmp %= MOD
        just = (tmp - cnt) % MOD
        ans += just * k
        ans %= MOD
        cnt = tmp
    return ans


n = int(input())
print(solve(n))