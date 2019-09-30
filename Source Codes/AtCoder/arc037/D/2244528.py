import sys
sys.setrecursionlimit(10**6)
L = int(input())
MOD = 10**9 + 7

memo = {}
def tri(L, m):
    if (L, m) in memo:
        return memo[L, m]
    if L == 0:
        if m == 0:
            return 2
        return 1
    res = 0
    if m == 0:
        res += tri(L-1, 0)**2
        res += tri(L-1, 0) * (tri(L-1, 0)**2 - tri(L-1, 1)**2)
    else:
        res += tri(L-1, 1) * (tri(L-1, 0)**2 - tri(L-1, 1)**2)
    r = memo[L, m] = res % MOD
    return r

def begin(L):
    if L == 0:
        return 1
    return (3*begin(L-1) + tri(L-1, 0)**3) % MOD

print(begin(L))