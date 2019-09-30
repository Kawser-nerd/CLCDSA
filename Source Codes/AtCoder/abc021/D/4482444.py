N = int(input())
K = int(input())
mod = 10 ** 9 + 7


class FactMod:

    def __init__(self, n, mod):
        self.mod = mod
        self.f = [1] * (n + 1)
        for i in range(1, n + 1):
            self.f[i] = self.f[i - 1] * i % mod

        self.inv = [pow(self.f[-1], mod - 2, mod)]
        for i in reversed(range(1, n + 1)):
            self.inv.append(self.inv[-1] * i % mod)
        self.inv.reverse()

    def fact(self, n):
        """
        :return: n!
        """
        return self.f[n]

    def comb(self, n, r):
        """
        :return: nCr
        """
        return self.f[n] * self.inv[n - r] * self.inv[r] % mod


factmod = FactMod(N + K, mod)
print(factmod.comb(N + K - 1, K))