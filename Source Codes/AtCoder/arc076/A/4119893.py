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


N, M = map(int, input().split())

mod = 10**9+7
ans = 0
F = FactMod(max(N, M), mod)

if abs(N-M) == 1:
    ans = F.fact(N)*F.fact(M) % mod
elif N == M:
    ans = F.fact(N)*F.fact(N)*2 % mod
else:
    ans = 0

print(ans)