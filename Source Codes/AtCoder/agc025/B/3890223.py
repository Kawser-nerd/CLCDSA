class BigCombination(object):
    __slots__ = ["mod", "factorial", "inverse"]

    def __init__(self, mod: int = 10**9+7, max_n: int = 10**6):
        from itertools import accumulate

        self.mod = mod
        self.factorial = [1] + list(accumulate(range(1, max_n+1),
                                               lambda x, y: x * y % mod))

        max_inv, x = 1, self.factorial[-1]
        for bit in bin(mod-2)[:1:-1]:
            if bit == "1":
                max_inv = max_inv * x % mod
            x = x * x % mod
        self.inverse = (list(accumulate([max_inv] + list(range(max_n, 0, -1)),
                                        lambda x, y: x * y % mod)))[::-1]

    def get_combination(self, n, r):
        return self.factorial[n] * self.inverse[r] * self.inverse[n-r] % self.mod


if __name__ == "__main__":
    N, A, B, K = map(int, input().split())
    mod = 998244353
    big_comb = BigCombination(mod, N)
    get_comb = big_comb.get_combination
    answer = 0
    for a_count in range(N+1):
        if (K-a_count*A) % B == 0 and 0 <= (K-a_count*A) // B <= N:
            b_count = (K-a_count*A) // B
            answer = (answer + get_comb(N, a_count) * get_comb(N, b_count)) % mod

    print(answer)