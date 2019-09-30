
dist = lambda x, y: (y + 1440 if y < x else y) - x
def solve2(N, A):
    val = min(dist(A[0][0], A[1][1]), dist(A[1][0], A[0][1]))
    return 4 if val > 720 else 2

def solve(Ac, Aj, CD, JK):
    #if Ac + Aj <= 2:
    #    return solve2(Ac, CD) if Ac == 2 else solve2(Aj, JK) if Aj == 2 else 2
    A = sorted([x + ['C'] for x in CD] + [x + ['J'] for x in JK])
    S, C, J = 0, sum(x[1] - x[0] for x in CD), sum(x[1] - x[0] for x in JK)
    Bc, Bj, Bu = [], [], []
    for i in xrange(len(A)):
        a, b = A[i], A[(i + 1) % len(A)]
        d = dist(a[1], b[0])
        if a[2] == b[2]:
            if d: (Bc if a[2] == 'C' else Bj).append(d)
        else:
            S += 1
            if d: Bu.append(d)
    fc = C + sum(Bc) > 720
    fj = J + sum(Bj) > 720
    if fc or fj:
        B, X = (Bc, C) if fc else (Bj, J)
        B.sort()
        while X + sum(B) > 720:
            B.pop()
            S += 2
    return S


T = int(raw_input())
for t in xrange(T):
    Ac, Aj = map(int, raw_input().split(' '))
    CD = [map(int, raw_input().split(' ')) for _ in xrange(Ac)]
    JK = [map(int, raw_input().split(' ')) for _ in xrange(Aj)]
    res = solve(Ac, Aj, CD, JK)
    print 'Case #%d: %s' % (t + 1, res)
