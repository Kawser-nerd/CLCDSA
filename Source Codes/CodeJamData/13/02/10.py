for test_case in xrange(1, int(raw_input()) + 1):
    N, M = map(int, raw_input().split())
    lawn = [[] for i in xrange(N)]

    for i in xrange(N):
        lawn[i] = map(int, raw_input().split())

    bad = False

    for height in xrange(100, 0, -1):
        good_rows = [False] * N
        good_cols = [False] * M

        for i in xrange(N):
            if max(lawn[i]) <= height:
                good_rows[i] = True

        for j in xrange(M):
            most = 0
            
            for i in xrange(N):
                most = max(most, lawn[i][j])

            if most <= height:
                good_cols[j] = True

        for i in xrange(N):
            for j in xrange(M):
                if lawn[i][j] <= height and not (good_rows[i] or good_cols[j]):
                    bad = True

    print "Case #{0}: {1}".format(test_case, "NO" if bad else "YES")