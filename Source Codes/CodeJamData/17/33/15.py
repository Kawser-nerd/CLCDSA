
def check(V, U, P):
    return sum(V - x for x in P if x < V) <= U

def solve(N, K, U, P):
    L, R = 0.0, 1.0
    if (check(R, U, P)):
        return R
    while R - L > 1e-10:
        M = (L + R) / 2.0
        if check(M, U, P):
            L = M
        else:
            R = M
    res = 1.0
    for x in P:
        res *= max(x, L)
    return res
    

T = int(raw_input())
for t in xrange(T):
    N, K = map(int, raw_input().split(' '))
    U = float(raw_input())
    P = map(float, raw_input().split(' '))
    res = solve(N, K, U, P)
    print 'Case #%d: %s' % (t + 1, res)
