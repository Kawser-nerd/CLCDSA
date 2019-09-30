import fractions

def distance2(p):
    return p[0] ** 2 + p[1] ** 2

def normalize(p):
    g = fractions.gcd(abs(p[0]), abs(p[1]))
    return p[0] / g, p[1] / g

def solve():
    H, W, D = map(int, raw_input().split())
    for j in xrange(H):
        raw = raw_input()
        for i in xrange(W):
            if raw[i] == 'X':
                place = (i, j)
    dx = (W - place[0] - 1) * 2 - 1
    dy = (H - place[1] - 1) * 2 - 1
    H2 = (H - 2) * 2
    W2 = (W - 2) * 2
    D2 = D ** 2
    points = set()
    for j in xrange(-(D/H2 + 1), D/H2 + 1):
        for i in xrange(-(D/W2 + 1), D/W2 + 1):
            p0 = (i * W2, j * H2)
            if p0 != (0, 0) and distance2(p0) <= D2:
                points.add(normalize(p0))
            p1 = (i * W2 + dx, j * H2)
            if distance2(p1) <= D2:
                points.add(normalize(p1))
            p2 = (i * W2, j * H2 + dy)
            if distance2(p2) <= D2:
                points.add(normalize(p2))
            p3 = (i * W2 + dx, j * H2 + dy)
            if distance2(p3) <= D2:
                points.add(normalize(p3))
    return len(points)

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
