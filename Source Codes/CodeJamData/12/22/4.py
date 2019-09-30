def check(a, b, t):
    ax, ay = a
    bx, by = b

    if bx < 0 or bx >= M or by < 0 or by >= N:
        return None

    h = H - t * 10

    if max(lo[ay][ax], lo[by][bx]) + 50 > hi[by][bx]:
        return None

    if lo[by][bx] + 50 > hi[ay][ax]:
        return None

    wait = 0
    if h + 50 > hi[by][bx]:
        wait = (h - (hi[by][bx] - 50)) / 10.0
        h = hi[by][bx] - 50

    if t == 0 and wait == 0:
        return t

    if h >= lo[ay][ax] + 20:
        return t + wait + 1
    else:
        return t + wait + 10

if __name__ == '__main__':
    for caseno in xrange(int(raw_input())):
        H, N, M = [int(s) for s in raw_input().split()]
        hi = []
        lo = []
        for _ in xrange(N):
            hi += [[int(s) for s in raw_input().split()]]
        for _ in xrange(N):
            lo += [[int(s) for s in raw_input().split()]]

        best = []
        for _ in xrange(N):
            best += [[None] * M]

        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        q = [(0,0)]
        best[0][0] = 0
        while q:
            u, q = q[0], q[1:]
            t = best[u[1]][u[0]]
            for d in dirs:
                nx, ny = u[0] + d[0], u[1] + d[1]
                nt = check(u, (nx, ny), t)
                if nt is not None and (best[ny][nx] is None or best[ny][nx] > nt):
                    q += [(nx, ny)]
                    best[ny][nx] = nt


        res = best[N - 1][M - 1]
        print 'Case #%d: %.7f' % (caseno + 1, res)

