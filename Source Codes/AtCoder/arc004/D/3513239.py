def d_freedom_of_expression(N, M):
    """
    ??: http://www.learning-algorithms.com/entry/2017/06/15/151840

    ??:
    (1) N(??????)????????(???p????f_p???)
    (2) M???????????1(?????)??????
        (???????????????????????)
    (3) ????p?????f_p??p?, ???0?????????
        ??????????? nHr(M, f_p) ??
    (4) -1?????????(M-1)?????????????
        ???????????????2**(M-1)??
    (5) ?????????????????????

    e.g. N=-12, M=3???????????
        (?4??) |   | | | |-1|
        (?3??) |   | |3| |  |
        (?6??) |2 2| | | |  | => 4 * 3 * (-1)
        (?1??) |  1| |1| | 1|
    """
    class Combination(object):
        def __init__(self, mod):
            self.mod = mod

        def inv(self, x):
            y = 1
            while y % x != 0:
                y += self.mod
            return y // x

        def comb(self, n, r):
            if n < 0 or r < 0 or n < r:
                return 0
            if n - r < r:
                r = n - r
            ret = 1
            for i in range(r):
                ret = (ret * n) % self.mod
                n -= 1
                ret = (ret * self.inv(i + 1)) % self.mod
            return ret

        def comb_with_repetition(self, n, r):
            if n == 0 and r > 0:
                return 0
            if n >= 0 and r == 0:
                return 1
            return self.comb(n + r - 1, r)

    def prime_factorization_dict(n):
        if n == 1:
            return {2: 0}  # 1????0???????
        i = 2
        table = {}
        while i**2 <= n:
            table[i] = 0
            while n % i == 0:
                table[i] += 1
                n //= i
            if table[i] == 0:
                table.pop(i)
            i += 1
        if n > 1:
            table[n] = 1
        return table

    mod = 10**9 + 7
    n = abs(N)
    prime = prime_factorization_dict(n)
    c = Combination(mod)
    ans = 1
    for factor in prime.values():
        ans = (ans * c.comb_with_repetition(M, factor)) % mod
    ans = (ans * pow(2, M - 1)) % mod

    return ans

N, M = [int(i) for i in input().split()]
print(d_freedom_of_expression(N, M))