# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
# -*- coding: utf-8 -*-


class FactMod():
    '''
    mod????????fact??????????
    ??????????????????mod????????????
    '''

    def __init__(self, n, mod):
        '''
        ???????
        f:n??? i!??????????
        inv: (i!)^-1??????????
        '''
        self.mod = mod
        self.f = [1]*(n+1)
        for i in range(1, n+1):
            self.f[i] = self.f[i-1]*i % mod

        self.inv = [pow(self.f[-1], mod-2, mod)]
        for i in range(1, n+1)[::-1]:
            self.inv.append(self.inv[-1]*i % mod)
        self.inv.reverse()

    def fact(self, n):
        '''
        n!?????
        '''
        return self.f[n]

    def comb(self, n, r):
        '''
        nCr?????
        '''
        ret = self.f[n] * self.inv[n-r]*self.inv[r]
        ret %= self.mod
        return ret


N, K = map(int, input().split())
F = FactMod(N+K, 10**9+7)
if K >= N:
    print(F.comb(N, K % N))
else:
    print(F.comb(N-1+K, K))