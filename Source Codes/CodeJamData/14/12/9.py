import sys
sys.setrecursionlimit(2000)

fin = iter(sys.stdin)

T = int(next(fin))
for t in xrange(T):
    N = int(next(fin))
    g = [set() for i in xrange(N)]
    for i in xrange(N-1):
        X, Y = map(int, next(fin).split())
        g[X-1].add(Y-1)
        g[Y-1].add(X-1)

    def subtree_info(R, parent=None):
        branches = []
        for X in g[R]:
            if X != parent:
                del_count, size = subtree_info(X, R)
                branches.append((size - del_count, del_count, size, X))

        if len(branches) == 0:
            return 0, 1
        if len(branches) == 1:
            return branches[0][2], branches[0][2] + 1

        branches.sort(reverse=True)

        del_count = branches[0][1] + branches[1][1]
        size = branches[0][2] + branches[1][2] + 1
        for branch in branches[2:]:
            del_count += branch[2]
            size += branch[2]
        return del_count, size

    print 'Case #%d: %d' % (t + 1, min(subtree_info(R)[0] for R in xrange(N)))
