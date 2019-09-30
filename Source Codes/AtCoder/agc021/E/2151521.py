def solve(n, k):
    MOD = 998244353

    if n > k:
        return 0
    if n == 1:
        return pow(2, k - 1, MOD)

    pf, kf = 1, 1
    for m in range(2, k + 1):
        pf = kf
        kf *= m
        kf %= MOD
    inv = pow(kf, MOD - 2, MOD)
    invs = [1] * (k + 1)
    invs[k] = inv
    for m in range(k, 1, -1):
        inv *= m
        inv %= MOD
        invs[m - 1] = inv

    ans = 0
    if k & 1 == 0:
        r = k >> 1
        s = k - n + 1
        ans = pf * (invs[r] * invs[r - 1] - invs[s] * invs[k - s - 1]) % MOD

    for r in range(k // 2 + 1, k + 1):
        if r * 2 >= n + k:
            ans += kf * invs[r] * invs[k - r]
        else:
            s = r * 2 - n + 1
            ans += kf * (invs[r] * invs[k - r] - invs[s] * invs[k - s])
        ans %= MOD

    return ans


print(solve(*map(int, input().split())))