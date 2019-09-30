T = input()

from itertools import combinations

def pp(a):
    r = 1
    for x in a:
        r *= x
    return r

def pfor(c):
    K = len(c)
    dp = [[0 for i in range(K / 2 + 1)] for j in range(K + 1)]
    dp[0][0] = 1
    cp = 0
    # for i in combinations(range(K), K / 2):
    #     no = list(set(range(K)) - set(i))
    #     cp += pp([c[j] for j in i]) * pp([1 - c[j] for j in no])
    for i in range(K):
        for y in range(0, K / 2 + 1):
            dp[i + 1][y] = dp[i][y - 1] * c[i] + dp[i][y] * (1 - c[i])
    return dp[K][K / 2]

def slidebw(P, K):
    for i in range(K):
        yield P[:i] + P[-(K - i):], i
    yield P[:K], K


def solve(N, K, P):
    bp, bm, bj = -1, None, None
    for c, j in slidebw(sorted(P), K):
        cp = pfor(c)
        if cp > bp:
            bp, bm, bj = cp, c, j
    # print N, K, sorted(P), bp, sorted(bm), bj
    return '{:.9f}'.format(bp)

for i in range(1, T + 1):
    N, K = map(int, raw_input().strip().split())
    P = map(float, raw_input().strip().split())

    print 'Case #{}: {}'.format(i, solve(N, K, P))

# print pfor((0.0, 0.08, 0.0, 0.0, 0.61, 0.02, 0.04, 0.07))
