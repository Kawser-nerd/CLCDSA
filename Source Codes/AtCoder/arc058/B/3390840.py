class BigCombination(object):
    __slots__ = ["mod", "inverse_mod", "factorial", "inverse"]

    def __init__(self, mod: int = 10**9+7, max_n: int = 10**6):
        from itertools import accumulate
        self.mod = mod
        self.inverse_mod = tuple(map(int, bin(mod-2)[:1:-1]))
        self.factorial = [1] + list(accumulate(range(1, max_n+1),
                                    lambda x, y: x * y % mod))
        self.inverse = (list(accumulate([self.get_inverse(max_n)] +
                        list(range(max_n, 0, -1)), lambda x, y: x * y % mod)))[::-1]

    def get_inverse(self, x: int):
        x = self.factorial[x]
        result, _x, mod = 1, x, self.mod
        for bit in self.inverse_mod:
            if bit:
                result = result * _x % mod
            _x = _x * _x % mod

        return result

    def get_combination(self, n, r):
        return self.factorial[n] * self.inverse[r] * self.inverse[n-r] % self.mod


H, W, A, B = map(int, input().split())
mod = 10**9+7
big_comb = BigCombination(max_n=2*10**5)
comb = big_comb.get_combination
_A = H-A-1
print(sum(comb(x+_A, x)*comb(W-x-1+A-1, A-1) % mod for x in range(B, W)) % mod)