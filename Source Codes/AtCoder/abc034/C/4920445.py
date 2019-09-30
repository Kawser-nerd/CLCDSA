def mod_inv(n: int, mod: int)->int:
    b, u, v = mod, 1, 0
    while b > 0:
        t = n // b

        n -= t * b
        u -= t * v

        n, b = b, n
        u, v = v, u

    return (u+mod) % mod


def comb_mod(n: int, r: int, mod: int)->int:
    r = min(r, n-r)
    c = 1  # (n-r)C0

    # (n+1)C(r+1) = (n+1)x(nCr)
    for i in range(r):
        c = c * (n-(r-i)+1) * mod_inv(r-i, mod)
        c %= mod

    return c


def path(H: int, W: int)->int:
    MOD = 10**9 + 7
    return comb_mod((H-1)+(W-1), min(H-1, W-1), MOD)


if __name__ == "__main__":
    H, W = map(int, input().split())
    ans = path(H, W)
    print(ans)