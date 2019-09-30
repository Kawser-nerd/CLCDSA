import sys

def solve(startwith, constraints, N):
    available = set([(i, j) for i in xrange(N) for j in xrange(N)])
    c_left = {}
    constraints_by = {}
    for c in constraints:
        c_left[c] = len(c)
        for el in c:
            constraints_by.setdefault(el, []).append(c)

    def use(p):
        assert p in available
        # print "using", p
        for c in constraints_by[p]:
            # print "is in constraint", c
            for el in c:
                if el in available:
                    available.remove(el)
                    for c2 in constraints_by[el]:
                        c_left[c2] -= 1

    # print c_left, available
    for p in startwith:
        use(p)
        # print c_left, available

    rtn = []
    while available:
        best = None
        best_score = 100000
        for c, count in c_left.iteritems():
            if count > 0 and count < best_score:
                best_score = count
                best = c
        assert best

        for el in best:
            if el in available:
                use(el)
                rtn.append(el)
                break
        else:
            assert 0

        """
        for c, count in c_left.iteritems():
            if count == 1:
                for el in c:
                    if el in available:
                        use(el)
                        rtn.append(el)
                        break
                else:
                    assert 0
                break
        else:
            el = list(available)[0]
            use(el)
            rtn.append(el)
        """

    # print rtn
    return rtn

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        if fn != '-':
            f = open(fn)

    T = int(f.readline())
    for _T in xrange(T):
        N, M = map(int, f.readline().split())

        grid = [['.'] * N for i in xrange(N)]
        pluses = []
        xs = []
        points = 0
        for i in xrange(M):
            m, r, c = f.readline().split()
            r = int(r) - 1
            c = int(c) - 1
            grid[r][c] = m
            if m in "xo":
                xs.append((r, c))
            if m in "+o":
                pluses.append((r, c))
            if m == 'o':
                points += 2
            else:
                points += 1

        # for g in grid:
            # print g

        rows_cols = []
        rows_cols += [tuple([(i, j) for i in xrange(N)]) for j in xrange(N)]
        rows_cols += [tuple([(j, i) for i in xrange(N)]) for j in xrange(N)]
        use_xs = set(solve(xs, rows_cols, N))

        diags = []
        diags += [tuple([(i, k - i) for i in xrange(k+1)]) for k in xrange(N)]
        diags += [tuple([(N - i - 1, N - k + i -1) for i in xrange(k+1)]) for k in xrange(N-1)]
        diags += [tuple([(N - i - 1, k - i) for i in xrange(k+1)]) for k in xrange(N)]
        diags += [tuple([(i, N - k + i -1) for i in xrange(k+1)]) for k in xrange(N-1)]
        use_ps = set(solve(pluses, diags, N))

        use_os = use_xs.intersection(use_ps)
        use_xs = use_xs - use_os
        use_ps = use_ps - use_os

        # print use_os, use_xs, use_ps

        print "Case #%d: %d %d" % (_T + 1, points + 2 * len(use_os) + len(use_xs) + len(use_ps), len(use_os) + len(use_xs) + len(use_ps))
        for i, j in use_os:
            print "o %d %d" % (i + 1, j + 1)
        for i, j in use_ps:
            assert grid[i][j] in ".x"
            if grid[i][j] == 'x':
                print "o %d %d" % (i + 1, j + 1)
            else:
                print "+ %d %d" % (i + 1, j + 1)
        for i, j in use_xs:
            assert grid[i][j] in ".+"
            if grid[i][j] == '+':
                print "o %d %d" % (i + 1, j + 1)
            else:
                print "x %d %d" % (i + 1, j + 1)
