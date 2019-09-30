def d_winter(R, C, X, Y, D, L):
    class PermutationCombination(object):
        """??: https://harigami.net/contents?id=5f169f85-5707-4137-87a5-f0068749d9bb"""
        __slots__ = ["mod", "factorial", "inverse"]

        def __init__(self, max_n: int = 10**6, mod: int = 10**9 + 7):
            fac, inv = [1], []
            fac_append, inv_append = fac.append, inv.append

            for i in range(1, max_n + 1):
                fac_append(fac[-1] * i % mod)

            inv_append(pow(fac[-1], mod - 2, mod))

            for i in range(max_n, 0, -1):
                inv_append(inv[-1] * i % mod)

            self.mod, self.factorial, self.inverse = mod, fac, inv[::-1]

        def combination(self, n, r):
            if r == n or r == 0:
                return 1
            if r > n:
                return 0
            return self.factorial[n] * self.inverse[r] * self.inverse[n - r] % self.mod

    MOD = 10**9 + 7
    parted_region_pattern = (R - X + 1) * (C - Y + 1)

    if X * Y == D + L:
        # ??????????????????????
        desk_pattern = PermutationCombination(X * Y, MOD).combination(X * Y, D)
        # == nCr(X*Y,L,M)
    else:
        # X*Y=D+L???????????????????????????
        # ????????????????????????????
        # ???????XY??????/???/???/?????????/???
        # ?????????????????
        N = D + L
        c = PermutationCombination(max(N, X * Y), MOD)
        desk_pattern = c.combination(X * Y, N)  # ????????0?
        desk_pattern += (-2 * (c.combination(X * (Y - 1), N)
                               + c.combination((X - 1) * Y, N)))  # 1?
        desk_pattern += (c.combination((X - 2) * Y, N)
                         + c.combination(X * (Y - 2), N)
                         + 4 * c.combination((X - 1) * (Y - 1), N))  # 2?
        desk_pattern += (-2 * (c.combination((X - 2) * (Y - 1), N)
                               + c.combination((X - 1) * (Y - 2), N)))  # 3?
        desk_pattern += c.combination((X - 2) * (Y - 2), N)  # 4?
        desk_pattern *= c.combination(N, D)  # ??????????????
        desk_pattern %= MOD
    return (parted_region_pattern * desk_pattern) % MOD

R, C = [int(i) for i in input().split()]
X, Y = [int(i) for i in input().split()]
D, L = [int(i) for i in input().split()]
print(d_winter(R, C, X, Y, D, L))