ip = lambda : map(int, raw_input().split())

def solve(cas):
    print 'Case #%d:' % cas,
    n, q = ip()
    E = [0] * n
    S = [0] * n
    for i in xrange(n):
        E[i], S[i] = ip()
    D = []
    for i in xrange(n):
        D.append(ip())
        D[i][i] = 0
    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                if D[i][k] != -1 and D[k][j] != -1:
                    if D[i][j] == -1 or D[i][j] > D[i][k] + D[k][j]:
                        D[i][j] = D[i][k] + D[k][j]
    G = []
    for i in xrange(n):
        G.append([1e200] * n)
        G[i][i] = 0
        for j in xrange(n):
            if D[i][j] != -1 and E[i] >= D[i][j]:
                G[i][j] = 1.0 * D[i][j] / S[i];
    for k in xrange(n):
        for i in xrange(n):
            for j in xrange(n):
                G[i][j] = min(G[i][j], G[i][k] + G[k][j])
    for i in xrange(q):
        u, v = ip()
        print '%.10f' % G[u - 1][v - 1],
    print ''

for i in xrange(int(raw_input())):
    solve(i + 1)
