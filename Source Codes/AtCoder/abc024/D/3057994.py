def d_dynamic_programming(A, B, C):
    # c = (BC-AB)//(AC-BC+AB), r = (BC-AC)//(AB-BC+AC)
    # Python????????????????
    MOD = 10**9 + 7
    c = ((B * C - A * B) * pow(A * C - B * C + A * B, MOD - 2, MOD)) % MOD
    r = ((B * C - A * C) * pow(A * B - B * C + A * C, MOD - 2, MOD)) % MOD
    ans = '{} {}'.format(r, c)
    return ans

A, B, C = [int(input()) for _ in range(3)]
print(d_dynamic_programming(A, B, C))