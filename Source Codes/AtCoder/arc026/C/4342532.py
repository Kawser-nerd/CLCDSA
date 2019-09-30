# coding:utf-8

import sys
from operator import itemgetter


INF = float('inf')
MOD = 10 ** 9 + 7


def LI(): return [int(x) for x in sys.stdin.readline().split()]


class SegmentTree:
    __slots__ = ['node', 'size']

    def __init__(self, n_):
        self.size = 2 ** n_.bit_length()
        self.node = [INF] * (2 * self.size)

    # k?????a???
    def update(self, k, a):
        k += self.size - 1
        self.node[k] = a
        # ???????
        while k >= 0:
            k = (k - 1) // 2
            self.node[k] = min(self.node[k * 2 + 1], self.node[k * 2 + 2])

    # [a, b)????????
    def query(self, a, b):
        l, r = a + self.size, b + self.size
        res = INF
        while l < r:
            if r & 1:
                r -= 1
                res = min(res, self.node[r - 1])

            if l & 1:
                res = min(res, self.node[l - 1])
                l += 1

            l >>= 1
            r >>= 1
        return res


n, L = LI()
sgt = SegmentTree(L + 1)
Q = [tuple(LI()) for _ in range(n)]
Q.sort()

dp = [INF] * (L + 1)
dp[0] = 0
sgt.update(0, 0)
for i in range(n):
    l, r, c = Q[i]
    cost = sgt.query(l, r) + c
    if cost < dp[r]:
        dp[r] = cost
        sgt.update(r, cost)

print(dp[-1])