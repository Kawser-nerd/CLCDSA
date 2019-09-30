def d_dynamic_programming(A, B, C):
    MOD = 10**9 + 7
    c = (((B * C - A * B + MOD) % MOD) * pow((A * C - B * C + A * B + MOD) % MOD, MOD - 2, MOD)) % MOD
    r = (((B * C - A * C + MOD) % MOD) * pow((A * B - B * C + A * C + MOD) % MOD, MOD - 2, MOD)) % MOD
    ans = '{} {}'.format(r, c)
    return ans

A, B, C = [int(input()) for _ in range(3)]
print(d_dynamic_programming(A, B, C))