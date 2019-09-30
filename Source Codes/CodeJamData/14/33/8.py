memo = {}

def AreaStone(n, m):
    return n * m + 2 * n + 2 * m, 2 * n + 2 * m

def solve():
    N, M, K = map(int, raw_input().split())
    l = []
    for i in xrange(N * M + 1):
        l.append((i, i))
    if N >= 4 and M >= 4:
        l.append((10, 7))
    if (N >= 4 and M >= 5) or (N >= 5 and M >= 4):
        l.append((14, 9))
    for n in xrange(N - 1):
        for m in xrange(M - 1):
            area, stone = AreaStone(n, m)
            l.append((area, stone))
            l.append((area + 1, stone + 1))
            l.append((area + 2, stone + 2))
            l.append((area + 3, stone + 3))
            l.append((area + 4, stone + 4))
    l.sort()
    for area, stone in l:
        if area >= K:
            return stone
    return 0

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
