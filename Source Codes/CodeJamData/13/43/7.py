from sys import stdin

testcases = int(stdin.readline())


for testcase in xrange(1, testcases + 1):
    N = int(stdin.readline())
    A = map(int, stdin.readline().split())
    B = map(int, stdin.readline().split())

    g = []
    for i in xrange(N):
        g.append([0] * N)

    for i in xrange(1, N):
        less_one = True
        for j in xrange(i - 1, -1, -1):
            if A[j] == A[i] - 1 and less_one:
                g[i][j] = 1
                less_one = False
            if A[j] >= A[i]:
                g[j][i] = 1

    for i in xrange(N - 2, -1, -1):
        less_one = True
        for j in xrange(i + 1, N):
            if B[j] == B[i] - 1 and less_one:
                g[i][j] = 1
                less_one = False
            if B[j] >= B[i]:
                g[j][i] = 1

    result = [0] * N
    d = [0] * N
    for i in xrange(N):
        for j in xrange(N):
            d[i] += g[i][j]

    for i in xrange(N):
        for x in xrange(N):
            if d[x] == 0:
                result[x] = i + 1
                for j in xrange(N):
                    if g[j][x]:
                        g[j][x] = 0
                        d[j] -= 1
                d[x] = -1
                break

    print 'Case #%d: %s' % (testcase, ' '.join(map(str, result)))
