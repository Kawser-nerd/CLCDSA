class BigCombination(object):
    __slots__ = ["mod", "factorial", "inverse"]

    def __init__(self, mod: int = 10**9+7, max_n: int = 10**6):
        fac, inv = [1], []
        fac_append, inv_append = fac.append, inv.append

        for i in range(1, max_n+1):
            fac_append(fac[-1] * i % mod)

        inv_append(pow(fac[-1], mod-2, mod))

        for i in range(max_n, 0, -1):
            inv_append(inv[-1] * i % mod)

        self.mod, self.factorial, self.inverse = mod, fac, inv[::-1]

    def get_combination(self, n, r):
        return self.factorial[n] * self.inverse[r] * self.inverse[n-r] % self.mod


if __name__ == "__main__":
    from itertools import product
    R, C = map(int, input().split())
    X, Y = map(int, input().split())
    D, L = map(int, input().split())
    mod = 10**9+7
    comb = BigCombination(mod, X*Y)
    get_comb = comb.get_combination

    square_comb = (R-X+1) * (C-Y+1)
    ans = 0

    for a in product((0, 1), repeat=4):
        x, y = (X - sum(a[:2])), (Y - sum(a[2:]))
        if min(x, y) <= 0 or D + L > x * y:
            continue
        ans = (ans + get_comb(x*y, D+L) * get_comb(D+L, D) * (-1 if a.count(1) % 2 == 1 else 1)) % mod

    print(ans * square_comb % mod)