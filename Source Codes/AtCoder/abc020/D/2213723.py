# seishin.py
N, K = map(int, input().split())

# ?????
F = {}
X = 2; Y = K
while X*X <= Y:
    if Y % X == 0:
        cnt = 0
        while Y % X == 0:
            Y //= X
            cnt += 1
        F[X] = cnt
    X += 1
if Y > 1:
    F[Y] = 1

*P, = sorted(F.items())
*E, = sorted(F.keys())
L = len(P)

from itertools import compress, combinations

MOD = 10**9 + 7

# GCD(i, K) = v ???i (1?i?N)???LCM?
# => GCD(j, K/v) = 1 ???i (1?j?N/v)???LCM??v?????
# => LCM(i, K/v)*v = i*(K/v)/GCD(i, K/v) * v = i*K/GCD(i, K/v) ???
def calc(v, M):
    *e, = compress(E, M)
    N0 = N // v
    res = N0*(N0 + 1) // 2
    # K/v ?????????????????????
    for l in range(1, len(e)+1):
        for P in combinations(e, l):
            u = 1
            for p in P: u *= p
            c = N0 // u
            if l % 2:
                res -= u*c*(c+1)//2
            else:
                res += u*c*(c+1)//2
        res %= MOD
    # i*K / GCD(i, K) ???K?
    res *= K
    return res % MOD

# ???????
def dfs(c, v, M):
    if c == L:
        return calc(v, M)
    x, k = P[c]
    r = 0
    for i in range(k+1):
        # K/v ? x ?????????M[c] = 1
        M[c] = (i < k)
        r += dfs(c+1, v, M)
        v *= x
    return r % MOD
print(dfs(0, 1, [0]*L))