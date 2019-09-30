def d_multi_loop(N, K):
    class Combination(object):
        def __init__(self, n, mod):
            self.mod = mod
            # ??????????????????
            self.factorial = [1] * (n + 1)  # 0!??n!??????
            for k in range(1, n):
                self.factorial[k + 1] = (self.factorial[k] * (k + 1)) % mod
            # k!?mod?????????
            self.fact_inv = [1] * (n + 1)
            self.fact_inv[n] = pow(self.factorial[n], mod - 2, mod)
            for k in reversed(range(1, n + 1)):
                self.fact_inv[k - 1] = (self.fact_inv[k] * k) % mod

        def comb(self, n, r):
            if n < 0 or r < 0 or n < r:
                return 0
            return (self.factorial[n] * self.fact_inv[r] * self.fact_inv[n - r]) % self.mod

        def comb_with_repetition(self, n, r):
            if n == 0 and r > 0:
                return 0
            if n >= 0 and r == 0:
                return 1
            return self.comb(n + r - 1, r)

    ans = Combination(N + K, 10**9 + 7).comb_with_repetition(N, K)
    return ans
  
N = int(input())
K = int(input())
print(d_multi_loop(N, K))