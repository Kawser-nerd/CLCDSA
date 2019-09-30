tests = int(input())

d = {'>': (0, 1), '<': (0, -1), '^': (-1, 0), 'v': (1, 0)}

for t in range(1, tests+1):
    n, m = map(int, input().split())
    bounds = lambda x, y: (0 <= x < n) and (0 <= y < m)
    f = [input() for _ in range(n)]
    total, fail = 0, False
    def safe(x, y, d):
        x += d[0]
        y += d[1]
        while bounds(x, y):
            if f[x][y] != '.':
                return True
            x += d[0]
            y += d[1]
        return False
    for i in range(n):
        for j in range(m):
            if f[i][j] == '.':
                continue
            dd = d[f[i][j]]
            if safe(i, j, dd):
                continue
            if all(not safe(i, j, d[q]) for q in '<>^v'):
                fail = True
            else:
                total += 1
    print('Case #{}: {}'.format(t, 'IMPOSSIBLE' if fail else total))
