import sys

def works():
    found = [[0] * M for _ in xrange(N)]
    q = []
    tot = 0

    for i in xrange(N):
        if grid[i][0] == 0:
            found[i][0] = 1
            tot += 1
            q.append((i, 0))
        if M > 1:
            if grid[i][M-1] == 0:
                found[i][M-1] = 1
                tot += 1
                q.append((i, M-1))

    for j in xrange(1,M-1):
        if grid[0][j] == 0:
            found[0][j] = 1
            tot += 1
            q.append((0, j))
        if N > 1:
            if grid[N-1][j] == 0:
                found[N-1][j] = 1
                tot += 1
                q.append((N-1, j))

    while q:
        r, c = q.pop()

        for dr, dc in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
            nr, nc = r + dr, c + dc
            if nr < 0 or nr >= N or nc < 0 or nc >= M:
                continue
            if grid[nr][nc] == 0 and found[nr][nc] == 0:
                found[nr][nc] = 1
                tot += 1
                q.append((nr, nc))

    return N * M - tot >= K

def test(idx):
    if idx == N * M:
        if works():
            return sum(map(sum, grid))
        return 10000

    r, c = idx / M, idx % M

    grid[r][c] = 0
    a = test(idx + 1)
    grid[r][c] = 1
    b = test(idx + 1)
    return min(a, b)

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, M, K = map(int, f.readline().split())

        grid = [[0] * M for _ in xrange(N)]

        r = test(0)
        print "Case #%d: %d" % (_T+1, r)
