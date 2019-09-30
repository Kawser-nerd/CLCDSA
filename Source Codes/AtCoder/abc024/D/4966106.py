def mod_inv(n: int, mod: int)->int:
    b, u, v = mod, 1, 0
    while b > 0:
        t = n // b

        n -= t * b
        u -= t * v

        n, b = b, n
        u, v = v, u

    return (u+mod) % mod


def dp(A: int, B: int, C: int)->tuple:
    MOD = 10**9 + 7

    r = ((B*C - A*C) % MOD * mod_inv(A*C - (B*C - A*B), MOD)) % MOD
    c = ((B*C - A*B) % MOD * mod_inv(A*C - (B*C - A*B), MOD)) % MOD

    return r, c


if __name__ == "__main__":
    A, B, C = [int(input()) for _ in range(3)]
    r, c = dp(A, B, C)
    print(r, c)