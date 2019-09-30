import sys

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        R, C = map(int, f.readline().split())

        grid = []
        for i in xrange(R):
            grid.append(list(f.readline().strip()))


        for l in grid:
            for i in xrange(1, C):
                if l[i] == '?' and l[i - 1] != '?':
                    l[i] = l[i - 1]
            for i in xrange(C - 2, -1, -1):
                if l[i] == '?' and l[i + 1] != '?':
                    l[i] = l[i + 1]

        for r in xrange(1, R):
            for c in xrange(C):
                if grid[r][c] == '?' and grid[r - 1][c] != '?':
                    grid[r][c] = grid[r - 1][c]
        for r in xrange(R - 2, -1, -1):
            for c in xrange(C):
                if grid[r][c] == '?' and grid[r + 1][c] != '?':
                    grid[r][c] = grid[r + 1][c]

        for r in xrange(R):
            for c in xrange(C):
                assert grid[r][c] != '?'

        print "Case #%d:" % (_T + 1,)
        for g in grid:
            print ''.join(g)
