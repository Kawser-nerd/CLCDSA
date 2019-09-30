
from math import pi


def solve(N, K, R, H):
    S_max = 0
    for i in xrange(N):
        C = [-2 * pi * R[j] * H[j] for j in xrange(N) if j != i and R[j] <= R[i]]
        S = pi * R[i] * R[i] + 2 * pi * R[i] * H[i] - sum(sorted(C)[:K - 1])
        S_max = max(S_max, S)
    return S_max
    

T = int(raw_input())
for t in xrange(T):
    N, K = map(int, raw_input().split(' '))
    A = [map(int, raw_input().split(' ')) for _ in xrange(N)]
    R, H = zip(*A)
    res = solve(N, K, R, H)
    print 'Case #%d: %s' % (t + 1, res)
